#include "hdr/SetNTPTimestampFracSecRequestMessage.h"

#include "../header/hdr/CommandHeader.h"
#include "../body/hdr/SetNTPTimestampFracSecRequestBody.h"

#define BODY_LENGTH 10

SetNTPTimestampFracSecRequestMessage::SetNTPTimestampFracSecRequestMessage(uint32_t frac_seconds):Message(
		new CommandHeader(BODY_LENGTH), new SetNTPTimestampFracSecRequestBody(frac_seconds)) {
}