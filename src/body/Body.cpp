#include "hdr/Body.h"
#include "../util/hdr/BytesConverter.h"

#define RESERVED 0x00
#define BODY_SIZE_BY_DEFAULT 4

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
	bytes = bodyBytes;
}

Body::~Body() {
	delete [] bytes;
}

uint8_t * Body::getBytes() {
	return bytes;
}

int Body::getAmountBytes() {
	return BODY_SIZE_BY_DEFAULT;
}

void Body::showBytes() {
	BytesConverter::getInstance()->print(bytes, bodySize);
}

