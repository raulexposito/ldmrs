#include "hdr/ErrorAndWarningHeader.h"

#define ERROR_WARNING_HEADER_PREFFIX 0x20
#define ERROR_WARNING_HEADER_SUFFIX 0x30

ErrorAndWarningHeader::ErrorAndWarningHeader(int dataBlockSize):
			Header(dataBlockSize, ERROR_WARNING_HEADER_PREFFIX, ERROR_WARNING_HEADER_SUFFIX) {}

ErrorAndWarningHeader::ErrorAndWarningHeader(uint8_t * headerBytes):
			Header(headerBytes) {}

HeaderTypeEnum ErrorAndWarningHeader::getType() {
	return ERRORS_AND_WARNINGS;
}
