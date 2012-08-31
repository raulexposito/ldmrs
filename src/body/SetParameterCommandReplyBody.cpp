#include "hdr/SetParameterCommandReplyBody.h"
#include "util/hdr/ParameterConverter.h"

SetParameterCommandReplyBody::SetParameterCommandReplyBody(int bodySize, uint8_t * bodyBytes):
		Body(bodySize, bodyBytes) {
}

bool SetParameterCommandReplyBody::isSetParameterCommandReplyBody() {
	return true;
}

std::string SetParameterCommandReplyBody::asText() {
	std::stringstream text;
	text << "SET PARAMETER COMMAND REPLY" << "[";
	text << getAmountBytes() << "]:";
	// TODO: mostrar el parametro que se ha cambiado
	return text.str();
}
