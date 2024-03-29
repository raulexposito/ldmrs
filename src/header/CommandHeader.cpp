#include "hdr/CommandHeader.h"

#define COMMAND_HEADER_PREFFIX 0x20
#define COMMAND_HEADER_SUFFIX 0x10
#define HEADER_SIZE 24

CommandHeader::CommandHeader(int dataBlockSize):
			Header(dataBlockSize, COMMAND_HEADER_PREFFIX, COMMAND_HEADER_SUFFIX) {}

bool CommandHeader::isCommandHeader() {
	return true;
}

std::string CommandHeader::asText() {
	std::stringstream text;
	text << "COMMAND[" << getBodySize() + HEADER_SIZE << "]";
	return text.str();
}
