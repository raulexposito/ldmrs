#include "hdr/GetStatusCommandBody.h"

#define CODE_PREFFIX 0x01
#define CODE_SUFFIX 0x00
#define BODY_SIZE 4

GetStatusCommandBody::GetStatusCommandBody():
			Body(BODY_SIZE, CODE_PREFFIX, CODE_SUFFIX) {}

bool GetStatusCommandBody::isGetStatusCommandBody() {
	return true;
}

std::string GetStatusCommandBody::asText() {
	std::stringstream text;
	text << "GET STATUS COMMAND" << ":";
	text << getAmountBytes();
	return text.str();
}
