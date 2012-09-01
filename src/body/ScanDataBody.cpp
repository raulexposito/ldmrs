#include "hdr/ScanDataBody.h"

ScanDataBody::ScanDataBody(int bodySize, uint8_t * bodyBytes):
		Body(bodySize, bodyBytes) {
}

bool ScanDataBody::isScanDataBody() {
	return true;
}

std::string ScanDataBody::asText() {
	std::stringstream text;
	text << "SCAN DATA" << "[";
	text << getAmountBytes() << "]";
	// TODO: mostrar informacion relevante
	return text.str();
}
