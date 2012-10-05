#include "hdr/ResetCommandBody.h"
#include "../net/hdr/NetworkClient.h"
#include "../config/hdr/Configuration.h"

#define CODE_PREFFIX 0x00
#define CODE_SUFFIX 0x00
#define BODY_SIZE 4

ResetCommandBody::ResetCommandBody():
			Body(BODY_SIZE, CODE_PREFFIX, CODE_SUFFIX) {
	if (Configuration::getInstance()->getSource()==SOURCE_TCPIP) {
		NetworkClient::getInstance()->resetConnection();
	}
}

bool ResetCommandBody::isResetCommandBody() {
	return true;
}

std::string ResetCommandBody::asText() {
	std::stringstream text;
	text << "RESET COMMAND";
	return text.str();
}
