#include "hdr/SetNTPTimestampFracSecCommandMessage.h"

#include "../header/hdr/CommandHeader.h"
#include "../body/hdr/SetNTPTimestampFracSecCommandBody.h"

#define BODY_LENGTH 10

SetNTPTimestampFracSecCommandMessage::SetNTPTimestampFracSecCommandMessage(uint32_t frac_seconds):Message(
		new CommandHeader(BODY_LENGTH), new SetNTPTimestampFracSecCommandBody(frac_seconds)) {
}
