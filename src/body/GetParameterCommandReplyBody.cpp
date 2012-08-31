#include "hdr/GetParameterCommandReplyBody.h"
#include "util/hdr/ParameterConverter.h"

GetParameterCommandReplyBody::GetParameterCommandReplyBody(int bodySize, uint8_t * bodyBytes):
		Body(bodySize, bodyBytes) {
}

bool GetParameterCommandReplyBody::isGetParameterCommandReplyBody() {
	return true;
}

std::string GetParameterCommandReplyBody::asText() {
	std::stringstream text;
	text << "GET PARAMETER COMMAND REPLY" << "[";
	text << getAmountBytes() << "]:";
	// TODO: recuperar el tipo de parametro
	// TODO: recuperar el valor del parametro
	return text.str();
}
