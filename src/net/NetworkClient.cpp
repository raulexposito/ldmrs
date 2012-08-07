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

#define HEADER_LENGTH 24
#define LENGTH_FIRST_POSITION 8

NetworkClient* NetworkClient::instance = 0;

void logConfiguration ();

NetworkClient* NetworkClient::getInstance() {
   if (!instance)
	   instance = new NetworkClient;

   return instance;
}

NetworkClient::NetworkClient() {

	logConfiguration();

	struct sockaddr_in sockaddr;
	struct in_addr ipv4addr;
	struct servent *port;
	struct hostent *host;
	inet_pton(AF_INET, Configuration::getInstance()->getIp().c_str(), &ipv4addr);

	port = getservbyport(Configuration::getInstance()->getPort(), "tcp");
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
/*


	std::string message = "Connecting with LDMRS device:t";
	message.append();
	message.append(":");
	message.append(ipAsString.str());
	Logger::getInstance()->log(message.c_str());
*/
}

Message * NetworkClient::receive () {

	// TODO: partir este metodo y generar dos: el primero recupera el encabezado y el segundo el cuerpo

	uint8_t * receivedHeaderBytes = new uint8_t[HEADER_LENGTH];
	read (serverSocket, receivedHeaderBytes, HEADER_LENGTH);
	Header * header = HeaderFactory::getInstance()->generateHeader(receivedHeaderBytes);

	uint8_t * receivedBodyBytes = new uint8_t[header->getBodySize()];
	read (serverSocket, receivedBodyBytes, header->getBodySize());
	Body * body = BodyFactory::getInstance()->generateBody(header->getBodySize(), receivedBodyBytes);

	Message * message = new Message(header, body);
	Recorder::getInstance()->record(message);

	return message;
}

void NetworkClient::send (Message * message) {
	write (serverSocket, message->getBytesInRaw(), message->getAmountBytes());
}

