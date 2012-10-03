#include "hdr/CommandReplyHeader.h"

#define HEADER_SIZE 24

CommandReplyHeader::CommandReplyHeader(uint8_t * headerBytes):
			Header(headerBytes) {}

bool CommandReplyHeader::isCommandReplyHeader() {
	return true;
}

std::string CommandReplyHeader::asText() {
	std::stringstream text;
	text << "COMMAND REPLY[" << getBodySize() + HEADER_SIZE << "]";
	return text.str();
}
