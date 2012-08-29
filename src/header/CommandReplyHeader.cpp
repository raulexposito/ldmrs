#include "hdr/CommandReplyHeader.h"

CommandReplyHeader::CommandReplyHeader(uint8_t * headerBytes):
			Header(headerBytes) {}

bool CommandReplyHeader::isCommandReplyHeader() {
	return true;
}

std::string CommandReplyHeader::asText() {
	std::stringstream text;
	text << "COMMAND REPLY:" << getBodySize();
	return text.str();
}
