#include "hdr/HeaderFactory.h"
#include "../../log/hdr/Logger.h"
#include "../hdr/ScanDataHeader.h"
#include "../hdr/ErrorAndWarningHeader.h"
#include "../hdr/CommandHeader.h"
#include "../hdr/CommandReplyHeader.h"
#include "../../util/hdr/BytesConverter.h"

#define LENGTH_FIRST_POSITION 8
#define HEADER_SIZE 24

HeaderFactory* HeaderFactory::instance = 0;

HeaderFactory* HeaderFactory::getInstance() {
   if (!instance)
	   instance = new HeaderFactory;

   return instance;
}

Header* HeaderFactory::generateHeader (uint8_t * headerBytes) {

	if (headerBytes[14] == 0x22 && headerBytes[15] == 0x02) {
		return new ScanDataHeader(headerBytes);
	} else if (headerBytes[14] == 0x20 && headerBytes[15] == 0x30) {
		return new ErrorAndWarningHeader(headerBytes);
	} else if (headerBytes[14] == 0x20 && headerBytes[15] == 0x20) {
		return new CommandReplyHeader(headerBytes);
	}

	std::stringstream warnMessage;
	warnMessage << "[WARN] UNKNOWN TYPE OF RECEIVED HEADER: ";
	warnMessage << BytesConverter::getInstance()->toString(headerBytes, HEADER_SIZE);

	Logger::getInstance()->log(warnMessage.str());
	// return new Header(new uint8_t[HEADER_SIZE]);
	return NULL;
}

