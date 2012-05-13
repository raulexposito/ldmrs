#include "hdr/CommandReplyHeader.h"

#define COMMAND_REPLY_HEADER_PREFFIX 0x20
#define COMMAND_REPLY_HEADER_SUFFIX 0x20

CommandReplyHeader::CommandReplyHeader(int dataBlockSize):
			Header(dataBlockSize, COMMAND_REPLY_HEADER_PREFFIX, COMMAND_REPLY_HEADER_SUFFIX) {}
