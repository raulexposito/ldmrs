#include "hdr/ScanDataHeader.h"

ScanDataHeader::ScanDataHeader(uint8_t * headerBytes):
			Header(headerBytes) {}

bool ScanDataHeader::isScanDataHeader() {
	return true;
}
