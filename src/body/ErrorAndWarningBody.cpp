#include "hdr/ErrorAndWarningBody.h"

ErrorAndWarningBody::ErrorAndWarningBody(int bodySize, uint8_t * bodyBytes):
		Body(bodySize, bodyBytes) {
}

bool ErrorAndWarningBody::isErrorAndWarningBody() {
	return true;
}

std::string ErrorAndWarningBody::asText() {
	std::stringstream text;
	text << "ERROR AND WARNING" << "[";
	text << getAmountBytes() << "]";
	// TODO: mostrar informacion relevante
	return text.str();
}
