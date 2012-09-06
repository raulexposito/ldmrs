#include "hdr/StartMeasureCommandReplyBody.h"
#include "util/hdr/ParameterConverter.h"

StartMeasureCommandReplyBody::StartMeasureCommandReplyBody(int bodySize, uint8_t * bodyBytes):
		Body(bodySize, bodyBytes) {
}

bool StartMeasureCommandReplyBody::isStartMeasureCommandReplyBody() {
	return true;
}

std::string StartMeasureCommandReplyBody::asText() {
	std::stringstream text;
	text << "START MEASURE COMMAND REPLY" << "[";
	text << getAmountBytes() << "]:";
	return text.str();
}
