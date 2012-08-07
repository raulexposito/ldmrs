#include "hdr/CommandHeader.h"

#define COMMAND_HEADER_PREFFIX 0x20
#define COMMAND_HEADER_SUFFIX 0x10

CommandHeader::CommandHeader(int dataBlockSize):
			Header(dataBlockSize, COMMAND_HEADER_PREFFIX, COMMAND_HEADER_SUFFIX) {}

bool CommandHeader::isCommandHeader() {
	return true;
}
