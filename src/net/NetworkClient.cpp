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

#include <iostream>		// para 'cout'
#include <iomanip>		// para formateo de cout
using namespace std;	// para formateo de cout

#include "hdr/NetworkClient.h"

#define HOST "ldmrs_device"
#define PORT "ldmrs_port"

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

void NetworkClient::receive (int amountBytes) {
	uint8_t * received = new uint8_t[amountBytes];

	read (serverSocket, received, amountBytes);

	cout << "LLEGA: ";
	int i;
	for (i = 0; i < amountBytes; i++) {
		cout << setw(2) << setfill('0') << hex << uppercase << (int) received[i] << " ";
	}
	cout << dec << endl;

	free(received);
}

void NetworkClient::send (Message * message) {
	write (serverSocket, message->getBytes(), message->getAmountBytes());
	cout << "MANDO: ";
	message->showBytes();
	cout << endl;
}
