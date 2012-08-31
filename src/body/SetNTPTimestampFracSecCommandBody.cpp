#include "hdr/SetNTPTimestampFracSecCommandBody.h"

#define CODE_PREFFIX 0x31
#define CODE_SUFFIX 0x00
#define BODY_SIZE 4

SetNTPTimestampFracSecCommandBody::SetNTPTimestampFracSecCommandBody(uint32_t frac_seconds):
			Body(BODY_SIZE, CODE_PREFFIX, CODE_SUFFIX) {

	// TODO: tratar las fracciones de segundo
}

bool SetNTPTimestampFracSecCommandBody::isSetNTPTimestampFracSecCommandBody() {
	return true;
}

std::string SetNTPTimestampFracSecCommandBody::asText() {
	std::stringstream text;
	text << "SET NTP TIMESTAMP FRAC SEC COMMAND" << "[";
	text << getAmountBytes() << "]:";
	// TODO: mostrar el tiempo en cristiano
	return text.str();
}
