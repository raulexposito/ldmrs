#include "hdr/StartMeasureCommandBody.h"

#define CODE_PREFFIX 0x20
#define CODE_SUFFIX 0x00
#define BODY_SIZE 4

StartMeasureCommandBody::StartMeasureCommandBody():
			Body(BODY_SIZE, CODE_PREFFIX, CODE_SUFFIX) {}

bool StartMeasureCommandBody::isStartMeasureCommandBody() {
	return true;
}

std::string StartMeasureCommandBody::asText() {
	std::stringstream text;
	text << "START MEASURE COMMAND" << "[";
	text << getAmountBytes() << "]";
	return text.str();
}