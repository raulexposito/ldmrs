#include "hdr/StopMeasureCommandReplyBody.h"
#include "util/hdr/ParameterConverter.h"

StopMeasureCommandReplyBody::StopMeasureCommandReplyBody(int bodySize, uint8_t * bodyBytes):
		Body(bodySize, bodyBytes) {
}

bool StopMeasureCommandReplyBody::isStopMeasureCommandReplyBody() {
	return true;
}

std::string StopMeasureCommandReplyBody::asText() {
	std::stringstream text;
	text << "STOP MEASURE COMMAND REPLY" << "[";
	text << getAmountBytes() << "]:";
	return text.str();
}
