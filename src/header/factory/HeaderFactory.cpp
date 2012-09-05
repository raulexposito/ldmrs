#include "hdr/HeaderFactory.h"
#include "../hdr/ScanDataHeader.h"
#include "../hdr/ErrorAndWarningHeader.h"
#include "../hdr/CommandHeader.h"
#include "../hdr/CommandReplyHeader.h"

#define LENGTH_FIRST_POSITION 8

HeaderFactory* HeaderFactory::instance = 0;

HeaderFactory* HeaderFactory::getInstance() {
   if (!instance)
	   instance = new HeaderFactory;

   return instance;
}

Header* HeaderFactory::generateHeader (uint8_t * headerBytes) {

	Header *header;

	if (headerBytes[14] == 0x22 && headerBytes[15] == 0x02) {
		header = new ScanDataHeader(headerBytes);
	} else if (headerBytes[14] == 0x20 && headerBytes[15] == 0x30) {
		header = new ErrorAndWarningHeader(headerBytes);
	} else 	if (headerBytes[14] == 0x20 && headerBytes[15] == 0x20) {
		header = new CommandReplyHeader(headerBytes);
	}
	return header;
}

