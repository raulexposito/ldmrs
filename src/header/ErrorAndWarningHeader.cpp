#include "hdr/ErrorAndWarningHeader.h"

ErrorAndWarningHeader::ErrorAndWarningHeader(uint8_t * headerBytes):
			Header(headerBytes) {}

bool ErrorAndWarningHeader::isErrorAndWarningHeader() {
	return true;
}
