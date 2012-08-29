#include "hdr/ErrorAndWarningHeader.h"

ErrorAndWarningHeader::ErrorAndWarningHeader(uint8_t * headerBytes):
			Header(headerBytes) {}

bool ErrorAndWarningHeader::isErrorAndWarningHeader() {
	return true;
}

std::string ErrorAndWarningHeader::asText() {
	std::stringstream text;
	text << "ERROR AND WARNNG:" << getBodySize();
	return text.str();
}
