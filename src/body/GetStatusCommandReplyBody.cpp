#include "hdr/GetStatusCommandReplyBody.h"

// TODO: implementar todos los metodos que devuelven informacion

GetStatusCommandReplyBody::GetStatusCommandReplyBody(int bodySize, uint8_t * bodyBytes):
		Body(bodySize, bodyBytes) {
}

bool GetStatusCommandReplyBody::isGetStatusCommandReplyBody() {
	return true;
}

std::string GetStatusCommandReplyBody::asText() {
	std::stringstream text;
	text << "GET STATUS COMMAND REPLY" << "[";
	text << getAmountBytes() << "]:";
	// TODO: mostrar estado
	return text.str();
}
