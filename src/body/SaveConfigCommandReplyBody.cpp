#include "hdr/SaveConfigCommandReplyBody.h"

SaveConfigCommandReplyBody::SaveConfigCommandReplyBody(int bodySize, uint8_t * bodyBytes):
		Body(bodySize, bodyBytes) {
}

bool SaveConfigCommandReplyBody::isSaveConfigCommandReplyBody() {
	return true;
}

std::string SaveConfigCommandReplyBody::asText() {
	std::stringstream text;
	text << "SAVE CONFIG COMMAND REPLY" << "[";
	text << getAmountBytes() << "]";
	return text.str();
}

