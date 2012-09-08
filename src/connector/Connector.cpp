#include "hdr/Connector.h"
#include "../config/hdr/Configuration.h"
#include "../net/hdr/NetworkClient.h"

Connector::Connector() {

}


void Connector::action() {
	if (Configuration::getInstance()->getSource()==SOURCE_FILE) {
		// TODO: lectura desde el fichero con FileClient
	} else {
		NetworkClient::getInstance()->receive();
	}

}
