#include "hdr/ErrorAndWarningHeader.h"

#define HEADER_SIZE 24

ErrorAndWarningHeader::ErrorAndWarningHeader(uint8_t * headerBytes):
			Header(headerBytes) {}

bool ErrorAndWarningHeader::isErrorAndWarningHeader() {
	return true;
}

std::string ErrorAndWarningHeader::asText() {
	std::stringstream text;
	text << "ERROR AND WARNNG[" << getBodySize() + HEADER_SIZE << "]";
	return text.str();
}
