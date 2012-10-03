#include "hdr/Body.h"
#include "../util/hdr/BytesConverter.h"

#define RESERVED 0x00

Body::Body(int bodySize, uint8_t preffix, uint8_t suffix) {
	this->bodySize = bodySize;
	bytes = new uint8_t[bodySize];
	bytes[0] = preffix;
	bytes[1] = suffix;
	bytes[2] = RESERVED;
	bytes[3] = RESERVED;
}

Body::Body(int bodySize, uint8_t * bodyBytes) {
	this->bodySize = bodySize;
	bytes = new uint8_t[bodySize];
	int i = 0;
	for (i = 0; i < bodySize; i++) {
		bytes[i] = bodyBytes[i];
	}
}

Body::~Body() {
	delete [] bytes;
}

uint8_t * Body::getBytesInRaw() {
	return bytes;
}

int Body::getAmountBytes() {
	return this->bodySize;
}

bool Body::isGetParameterCommandBody() { return false; }

bool Body::isGetParameterCommandReplyBody() { return false; }

bool Body::isGetStatusCommandBody() { return false; }

bool Body::isGetStatusCommandReplyBody() { return false; }

bool Body::isResetCommandBody() { return false; }

bool Body::isSaveConfigCommandBody() { return false; }

bool Body::isSetNTPTimestampFracSecCommandBody() { return false; }

bool Body::isSetNTPTimestampFracSecCommandReplyBody() { return false; }

bool Body::isSetNTPTimestampSecCommandBody() { return false; }

bool Body::isSetNTPTimestampSecCommandReplyBody() { return false; }

bool Body::isSetParameterCommandBody() { return false; }

bool Body::isSetParameterCommandReplyBody() { return false; }

bool Body::isStartMeasureCommandBody() { return false; }

bool Body::isStartMeasureCommandReplyBody() { return false; }

bool Body::isStopMeasureCommandBody() { return false; }

bool Body::isStopMeasureCommandReplyBody() { return false; }

bool Body::isScanDataBody() { return false; }

bool Body::isErrorAndWarningBody() { return false; }

bool Body::isSaveConfigCommandReplyBody() { return false; }

std::string Body::asText() {
	std::stringstream text;
	text << "GENERIC BODY";
	return text.str();
}
