#include <stdio.h>
#include <sys/socket.h>
#include <unistd.h>
#include <stdint.h>
#include <string.h>
#include <sstream>

#include <sys/types.h>
#include <sys/un.h>
#include <netinet/in.h>
#include <netdb.h>
#include <stdlib.h>
#include <arpa/inet.h>

#include "hdr/NetworkClient.h"
#include "../header/factory/hdr/HeaderFactory.h"
#include "../body/factory/hdr/BodyFactory.h"
#include "../config/hdr/Configuration.h"
#include "../log/hdr/Logger.h"
#include "../log/hdr/Recorder.h"
#include "../util/hdr/BytesConverter.h"

#define HEADER_LENGTH 24
#define LENGTH_FIRST_POSITION 8
#define MAGIC_WORD_LENGTH 4
#define NEXT_STEP_LENGTH 1

#define SENT true
#define RECEIVED false

NetworkClient* NetworkClient::instance = 0;

NetworkClient* NetworkClient::getInstance() {
   if (!instance)
	   instance = new NetworkClient();

   return instance;
}

void NetworkClient::resetConnection () {
	instance = 0;
}

NetworkClient::NetworkClient() {

    struct sockaddr_in dest_addr;

    int sock=socket(PF_INET, SOCK_STREAM, 0);
    if (sock == -1)
    {
    	Logger::getInstance()->log("Error, could not open socket\n");
    	return;
    }

    dest_addr.sin_family = AF_INET;
    dest_addr.sin_port = htons(Configuration::getInstance()->getPort());
    dest_addr.sin_addr.s_addr = inet_addr(Configuration::getInstance()->getIp().c_str());
    memset(dest_addr.sin_zero, '\0', sizeof( dest_addr.sin_zero ));

    if (connect( sock, (struct sockaddr *)&dest_addr, sizeof(struct sockaddr)) == -1)
    {
    	Logger::getInstance()->log("Could not connect to remote host.\n");
    	return;
    }

	serverSocket = socket (AF_INET, SOCK_STREAM, 0);
	if (serverSocket == -1) {
		Logger::getInstance()->log("Connection failed!");
		return;
	}

	if (connect (
			serverSocket,
				 (struct sockaddr *)&dest_addr,
				 sizeof (sockaddr)) == -1)
	{
		Logger::getInstance()->log("Connection established!");
		return;
	}
}

Message * NetworkClient::receive () {
	Header * header = getHeader();
	Body * body = getBody(header);

	Message * message = new Message(header, body);
	log (RECEIVED, message);
	Recorder::getInstance()->record(message);

	return message;
}

Header * NetworkClient::getHeader () {
	Header * result = NULL;

	uint8_t * magicWordBytes = new uint8_t[MAGIC_WORD_LENGTH];
	uint8_t * restOfHeaderBytes = new uint8_t[HEADER_LENGTH - MAGIC_WORD_LENGTH];
	uint8_t * allReceivedHeaderBytes = new uint8_t[HEADER_LENGTH];

	while (result == NULL) {

		// leemos los primeros 4 caracteres, que deberian ser la palabra magica
		read (serverSocket, magicWordBytes, MAGIC_WORD_LENGTH);

		if (!isMagicWord(magicWordBytes)) {
			uint8_t * nextStepByte = new uint8_t[NEXT_STEP_LENGTH];
			while (!isMagicWord(magicWordBytes)) {

				read (serverSocket, nextStepByte, NEXT_STEP_LENGTH);

				int k = 0;
				for (k = 0; k < MAGIC_WORD_LENGTH - 1; k ++) {
					magicWordBytes[k] = magicWordBytes[k+1];
				}
				magicWordBytes[MAGIC_WORD_LENGTH - 1] = nextStepByte[0];
			}
		}

		// copiamos la palabra magica
		int i = 0;
		for (i = 0; i < MAGIC_WORD_LENGTH; i ++) {
			allReceivedHeaderBytes[i] = magicWordBytes[i];
		}

		// leemos y copiamos el resto del mesaje
		read (serverSocket, restOfHeaderBytes, HEADER_LENGTH - MAGIC_WORD_LENGTH);

		int j = 0;
		for (j = MAGIC_WORD_LENGTH; j < HEADER_LENGTH; j++) {
			allReceivedHeaderBytes[j] = restOfHeaderBytes[j - MAGIC_WORD_LENGTH];
		}

		// generamos un encabezado. Si no es valido devolvera null y seguiremos recorriendo la medicion del laser
		result = HeaderFactory::getInstance()->generateHeader(allReceivedHeaderBytes);
	}

	delete magicWordBytes;
	delete restOfHeaderBytes;
	delete allReceivedHeaderBytes;

	return result;
}

Body * NetworkClient::getBody (Header * header) {
	uint8_t * receivedBodyBytes = new uint8_t[header->getBodySize()];
	read (serverSocket, receivedBodyBytes, header->getBodySize());
	return BodyFactory::getInstance()->generateBody(header, receivedBodyBytes);
}

bool NetworkClient::isMagicWord (uint8_t * magicWord) {
	return (magicWord[0] == 0xAF && magicWord[1] == 0xFE &&
			magicWord[2] == 0xC0 && magicWord[3] == 0xC2);
}

void NetworkClient::send (Message * message) {
	log (SENT, message);
	write (serverSocket, message->getBytesInRaw(), message->getAmountBytes());
}


void NetworkClient::log (bool sent, Message * message) {
	std::stringstream logMessage;
	if (sent) {
		logMessage << "[SENT] ";
	} else {
		logMessage << "[REVC] ";
	}
	logMessage << message->asText();
	Logger::getInstance()->log(logMessage.str());
}

