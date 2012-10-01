#include "hdr/Connector.h"
#include "../config/hdr/Configuration.h"
#include "../net/hdr/NetworkClient.h"
#include "../file/hdr/FileClient.h"
#include "../log/hdr/Logger.h"

void Connector::sendMessage(Message * message) {
	if (Configuration::getInstance()->getSource()==SOURCE_TCPIP) {
		logNetworkConfiguration();
		NetworkClient::getInstance()->send(message);
		if (message->isScanDataMessage()) {
			NetworkClient::getInstance()->resetConnection();
		}
	}
}

Message * Connector::receiveMessage() {
	Message * message;
	if (Configuration::getInstance()->getSource()==SOURCE_TCPIP) {
		logNetworkConfiguration();
		message = NetworkClient::getInstance()->receive();
	} else {
		logFileConfiguration();
		message = FileClient::getInstance()->receive();
	}
	return message;
}

void Connector::logNetworkConfiguration () {

	if (!configurationHasBeenShown) {
		std::stringstream ip;
		std::stringstream port;
		ip << "\tIP Address: " << Configuration::getInstance()->getIp().c_str();
		port << "\t      Port: " << Configuration::getInstance()->getPort();
		Logger::getInstance()->log("Connecting with LDMRS device:");
		Logger::getInstance()->log("");
		Logger::getInstance()->log(ip.str());
		Logger::getInstance()->log(port.str());
		Logger::getInstance()->log("");
		configurationHasBeenShown = true;
	}
}

void Connector::logFileConfiguration() {
	if (!configurationHasBeenShown) {
		std::stringstream recordFile;
		recordFile << "\tRecord file: '";
		recordFile << Configuration::getInstance()->getPath();
		recordFile << "'";
		Logger::getInstance()->log("Reading a saved record:");
		Logger::getInstance()->log("");
		Logger::getInstance()->log(recordFile.str());
		Logger::getInstance()->log("");
		configurationHasBeenShown = true;
	}
}
