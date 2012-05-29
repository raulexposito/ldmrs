#include <stdio.h>
#include <sys/socket.h>
#include <unistd.h>
#include <stdint.h>
#include <string.h>

#include <sys/types.h>
#include <sys/un.h>
#include <netinet/in.h>
#include <netdb.h>
#include <stdlib.h>

#include "hdr/NetworkClient.h"
#include "../header/factory/hdr/HeaderFactory.h"

#define HOST "ldmrs_device"
#define PORT "ldmrs_port"

#define HEADER_LENGTH 24
#define LENGTH_FIRST_POSITION 8

NetworkClient* NetworkClient::instance = 0;

NetworkClient* NetworkClient::getInstance() {
   if (!instance)
	   instance = new NetworkClient;

   return instance;
}

NetworkClient::NetworkClient() {
	struct sockaddr_in sockaddr;
	struct servent *port;
	struct hostent *host;

	port = getservbyname (PORT, "tcp");
	if (port == NULL)
		return;

	host = gethostbyname (HOST);
	if (host == NULL)
		return;

	sockaddr.sin_family = AF_INET;
	sockaddr.sin_addr.s_addr = ((struct in_addr *)(host->h_addr))->s_addr;
	sockaddr.sin_port = port->s_port;

	serverSocket = socket (AF_INET, SOCK_STREAM, 0);
	if (serverSocket == -1)
		return;

	if (connect (
			serverSocket,
				 (struct sockaddr *)&sockaddr,
				 sizeof (sockaddr)) == -1)
	{
		return;
	}
}

Message * NetworkClient::receive () {
	uint8_t * receivedHeader = new uint8_t[HEADER_LENGTH];
	read (serverSocket, receivedHeader, HEADER_LENGTH);
	Header * header = HeaderFactory::getInstance()->generateHeader(receivedHeader);

	uint8_t * receivedBody = new uint8_t[header->getBodySize()];
	read (serverSocket, receivedBody, header->getBodySize());
	Body * body = BodyFactory::getInstance()->generateBody(header->getDataType(), receivedBody);

	Message * message = new Message(header, body);
	message->showBytes();
	return message;
}

void NetworkClient::send (Message * message) {
	write (serverSocket, message->getBytes(), message->getAmountBytes());
}

