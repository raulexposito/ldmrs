#include "hdr/Connector.h"
#include "../config/hdr/Configuration.h"
#include "../net/hdr/NetworkClient.h"
#include "../file/hdr/FileClient.h"

void Connector::sendMessage(Message * message) {
	if (Configuration::getInstance()->getSource()==SOURCE_TCPIP) {
		NetworkClient::getInstance()->send(message);
	}
}

Message * Connector::receiveMessage() {
	Message * message;
	if (Configuration::getInstance()->getSource()==SOURCE_TCPIP) {
		message = NetworkClient::getInstance()->receive();
	} else {
		message = FileClient::getInstance()->receive();
	}
	return message;
}
