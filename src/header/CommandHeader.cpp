#include "hdr/CommandHeader.h"

#define COMMAND_HEADER_PREFFIX 0x20
#define COMMAND_HEADER_SUFFIX 0x10

CommandHeader::CommandHeader(int dataBlockSize):
			Header(dataBlockSize, COMMAND_HEADER_PREFFIX, COMMAND_HEADER_SUFFIX) {}

CommandHeader::CommandHeader(uint8_t * headerBytes):
			Header(headerBytes) {}

HeaderTypeEnum CommandHeader::getDataType() {
	return COMMAND;
}
