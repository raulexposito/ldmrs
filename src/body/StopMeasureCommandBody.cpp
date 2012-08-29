#include "hdr/StopMeasureCommandBody.h"

#define CODE_PREFFIX 0x21
#define CODE_SUFFIX 0x00
#define BODY_SIZE 4

StopMeasureCommandBody::StopMeasureCommandBody():
			Body(BODY_SIZE, CODE_PREFFIX, CODE_SUFFIX) {}

bool StopMeasureCommandBody::isStopMeasureCommandBody() {
	return true;
}

std::string StopMeasureCommandBody::asText() {
	std::stringstream text;
	text << "STOP MEASURE BODY" << ":";
	text << getAmountBytes();
	return text.str();
}
