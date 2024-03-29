#include "hdr/StartMeasureCommandBody.h"
#include "../net/hdr/NetworkClient.h"
#include "../config/hdr/Configuration.h"

#define CODE_PREFFIX 0x20
#define CODE_SUFFIX 0x00
#define BODY_SIZE 4

StartMeasureCommandBody::StartMeasureCommandBody():
			Body(BODY_SIZE, CODE_PREFFIX, CODE_SUFFIX) {
	if (Configuration::getInstance()->getSource()==SOURCE_TCPIP) {
		NetworkClient::getInstance()->resetConnection();
	}
}

bool StartMeasureCommandBody::isStartMeasureCommandBody() {
	return true;
}

std::string StartMeasureCommandBody::asText() {
	std::stringstream text;
	text << "START MEASURE COMMAND";
	return text.str();
}
