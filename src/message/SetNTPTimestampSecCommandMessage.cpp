#include "hdr/SetNTPTimestampSecCommandMessage.h"

#include "../header/hdr/CommandHeader.h"
#include "../body/hdr/SetNTPTimestampSecCommandBody.h"

#define BODY_LENGTH 10

SetNTPTimestampSecCommandMessage::SetNTPTimestampSecCommandMessage(uint32_t seconds):Message(
		new CommandHeader(BODY_LENGTH), new SetNTPTimestampSecCommandBody(seconds)) {
}
