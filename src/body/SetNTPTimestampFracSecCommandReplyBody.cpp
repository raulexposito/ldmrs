#include "hdr/SetNTPTimestampFracSecCommandReplyBody.h"

SetNTPTimestampFracSecCommandReplyBody::SetNTPTimestampFracSecCommandReplyBody(int bodySize, uint8_t * bodyBytes):
		Body(bodySize, bodyBytes) {
}

bool SetNTPTimestampFracSecCommandReplyBody::isSetNTPTimestampFracSecCommandReplyBody() {
	return true;
}

std::string SetNTPTimestampFracSecCommandReplyBody::asText() {
	std::stringstream text;
	text << "SET NTP TIMESTAMP FRAC SEC COMMAND REPLY" << ":";
	text << getAmountBytes() << ":";
	// TODO: mostrar el tiempo recibido en cristiano
	return text.str();
}

