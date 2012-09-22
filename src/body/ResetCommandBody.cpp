#include "hdr/ResetCommandBody.h"

#define CODE_PREFFIX 0x00
#define CODE_SUFFIX 0x00
#define BODY_SIZE 4

ResetCommandBody::ResetCommandBody():
			Body(BODY_SIZE, CODE_PREFFIX, CODE_SUFFIX) {}

bool ResetCommandBody::isResetCommandBody() {
	return true;
}

std::string ResetCommandBody::asText() {
	std::stringstream text;
	text << "RESET COMMAND";
	return text.str();
}
