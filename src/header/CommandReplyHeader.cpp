#include "hdr/CommandReplyHeader.h"

CommandReplyHeader::CommandReplyHeader(uint8_t * headerBytes):
			Header(headerBytes) {}

bool CommandReplyHeader::isCommandReplyHeader() {
	return true;
}
