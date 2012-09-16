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

void logConfiguration ();

NetworkClient* NetworkClient::getInstance() {
   if (!instance)
	   instance = new NetworkClient();

   return instance;
}

NetworkClient::NetworkClient() {

	logConfiguration();

	struct sockaddr_in sockaddr;
	struct in_addr ipv4addr;
	struct servent *port;
	struct hostent *host;
	inet_pton(AF_INET, Configuration::getInstance()->getIp().c_str(), &ipv4addr);

	port = getservbyport(htons(Configuration::getInstance()->getPort()), "tcp");
	if (port == NULL) {
		Logger::getInstance()->log("Can't connect with port!");
		return;
	}

	host = gethostbyaddr(&ipv4addr, sizeof ipv4addr, AF_INET);
	if (host == NULL) {
		Logger::getInstance()->log("Can't connect with host!");
		return;
	}

	sockaddr.sin_family = AF_INET;
	sockaddr.sin_addr.s_addr = ((struct in_addr *)(host->h_addr))->s_addr;
	sockaddr.sin_port = port->s_port;

	serverSocket = socket (AF_INET, SOCK_STREAM, 0);
	if (serverSocket == -1) {
		Logger::getInstance()->log("Connection failed!");
		return;
	}

	if (connect (
			serverSocket,
				 (struct sockaddr *)&sockaddr,
				 sizeof (sockaddr)) == -1)
	{
		Logger::getInstance()->log("Connection established!");
		return;
	}

	synchronizationHasBeenNeeded = false;
}
void logConfiguration () {
	std::stringstream ip;
	std::stringstream port;
	ip << "\tIP Address: " << Configuration::getInstance()->getIp().c_str();
	port << "\t      Port: " << Configuration::getInstance()->getPort();

	Logger::getInstance()->log("Connecting with LDMRS device:");
	Logger::getInstance()->log("");
	Logger::getInstance()->log(ip.str());
	Logger::getInstance()->log(port.str());
	Logger::getInstance()->log("");
}

Message * NetworkClient::receive () {

	Header * header = recoverSavedHeaderOrReadTheNextOne();
	Body * body = getBody(header);

	if (header->isScanDataHeader()) {

		// Se almacena la cabecera del siguiente mensaje
		nextHeader = getHeader();

		if (synchronizationHasBeenNeeded) {
			// Se descarta el mensaje actual y se lee el siguente
			return receive();
		}
	}

	Message * message = new Message(header, body);
	log (RECEIVED, message);

	if (!synchronizationHasBeenNeeded) {
		Recorder::getInstance()->record(message);
	}

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
				for (k = 0; k < HEADER_LENGTH - 1; k ++) {
					magicWordBytes[k] = magicWordBytes[k+1];
				}
				magicWordBytes[HEADER_LENGTH - 1] = nextStepByte[0];
			}

			// hemos necesitado sincronizar
			synchronizationHasBeenNeeded = true;
		} else {

			// la palabra magica estaba al comienzo, no ha sido necesario sincronizar
			synchronizationHasBeenNeeded = false;
		}

		// copiamos la palabra magica
		int i = 0;
		for (i = 0; i < MAGIC_WORD_LENGTH; i ++) {
			allReceivedHeaderBytes[i] = magicWordBytes[i];
		}

		// leemos y copiamos el resto del mesaje
		read (serverSocket, restOfHeaderBytes, HEADER_LENGTH - MAGIC_WORD_LENGTH);
		int j = 0;
		for (j = 4; j < HEADER_LENGTH; j++) {
			allReceivedHeaderBytes[j] = restOfHeaderBytes[j - MAGIC_WORD_LENGTH];
		}

		// generamos un encabezado. Si no es valido devolvera null y seguiremos recorriendo la medicion del laser
		result = HeaderFactory::getInstance()->generateHeader(allReceivedHeaderBytes);
	}

	delete magicWordBytes;
	delete restOfHeaderBytes;

	return result;
}

Body * NetworkClient::getBody (Header * header) {
	uint8_t * receivedBodyBytes = new uint8_t[header->getBodySize()];
	read (serverSocket, receivedBodyBytes, header->getBodySize());
	return BodyFactory::getInstance()->generateBody(header, receivedBodyBytes);
}

Header * NetworkClient::recoverSavedHeaderOrReadTheNextOne() {
	Header * header;
	if (nextHeader == NULL) {
		header = getHeader();
	} else {
		header = nextHeader;
		nextHeader = NULL;
	}
	return header;
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

