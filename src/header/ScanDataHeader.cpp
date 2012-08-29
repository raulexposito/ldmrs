#include "hdr/ScanDataHeader.h"

ScanDataHeader::ScanDataHeader(uint8_t * headerBytes):
			Header(headerBytes) {}

bool ScanDataHeader::isScanDataHeader() {
	return true;
}

std::string ScanDataHeader::asText() {
	std::stringstream text;
	text << "SCAN DATA:" << getBodySize();
	return text.str();
}
