#include "hdr/ScanDataHeader.h"

#define HEADER_SIZE 24

ScanDataHeader::ScanDataHeader(uint8_t * headerBytes):
			Header(headerBytes) {}

bool ScanDataHeader::isScanDataHeader() {
	return true;
}

std::string ScanDataHeader::asText() {
	std::stringstream text;
	text << "SCAN DATA[" << getBodySize() + HEADER_SIZE << "]";
	return text.str();
}
