#include "hdr/SaveConfigCommandBody.h"

#define CODE_PREFFIX 0x04
#define CODE_SUFFIX 0x00
#define BODY_SIZE 4

SaveConfigCommandBody::SaveConfigCommandBody():
			Body(BODY_SIZE, CODE_PREFFIX, CODE_SUFFIX) {}

bool SaveConfigCommandBody::isSaveConfigCommandBody() {
	return true;
}

std::string SaveConfigCommandBody::asText() {
	std::stringstream text;
	text << "SAVE CONFIG COMMAND";
	return text.str();
}
