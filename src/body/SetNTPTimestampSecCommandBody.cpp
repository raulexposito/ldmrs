#include "hdr/SetNTPTimestampSecCommandBody.h"

#define CODE_PREFFIX 0x30
#define CODE_SUFFIX 0x00
#define BODY_SIZE 4

SetNTPTimestampSecCommandBody::SetNTPTimestampSecCommandBody(uint32_t seconds):
			Body(BODY_SIZE, CODE_PREFFIX, CODE_SUFFIX) {

	// TODO: tratar los segundos
}

bool SetNTPTimestampSecCommandBody::isSetNTPTimestampSecCommandBody() {
	return true;
}

std::string SetNTPTimestampSecCommandBody::asText() {
	std::stringstream text;
	text << "SET NTP TIMESTAMP SEC COMMAND" << "[";
	text << getAmountBytes() << "]:";
	// TODO: mostrar el tiempo en cristiano
	return text.str();
}
