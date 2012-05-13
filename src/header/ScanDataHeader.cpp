#include "hdr/ScanDataHeader.h"

#define SCAN_DATA_HEADER_PREFFIX 0x22
#define SCAN_DATA_HEADER_SUFFIX 0x02

ScanDataHeader::ScanDataHeader(int dataBlockSize):
			Header(dataBlockSize, SCAN_DATA_HEADER_PREFFIX, SCAN_DATA_HEADER_SUFFIX) {}
