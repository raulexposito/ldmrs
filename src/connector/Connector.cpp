#include "hdr/Connector.h"
#include "../config/hdr/Configuration.h"
#include "../net/hdr/NetworkClient.h"
#include "../file/hdr/FileClient.h"

Connector::Connector() {

}


void Connector::action() {
	if (Configuration::getInstance()->getSource()==SOURCE_FILE) {
		for (int i = 0; i < 100; i++) {
			Message * message = FileClient::getInstance()->receive();
			std::cout << message->asText() << std::endl;
		}
	} else {
		NetworkClient::getInstance()->receive();
	}

}
