#include "hdr/SetNTPTimestampSecCommandReplyBody.h"

SetNTPTimestampSecCommandReplyBody::SetNTPTimestampSecCommandReplyBody(int bodySize, uint8_t * bodyBytes):
		Body(bodySize, bodyBytes) {
}

bool SetNTPTimestampSecCommandReplyBody::isSetNTPTimestampSecCommandReplyBody() {
	return true;
}

std::string SetNTPTimestampSecCommandReplyBody::asText() {
	std::stringstream text;
	text << "SET NTP TIMESTAMP FRAC SEC COMMAND REPLY" << ":";
	text << getAmountBytes() << ":";
	// TODO: mostrar el tiempo recibido en cristiano
	return text.str();
}
