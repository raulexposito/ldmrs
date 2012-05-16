#include "hdr/SetNTPTimestampSecRequestMessage.h"

#include "../header/hdr/CommandHeader.h"
#include "../body/hdr/SetNTPTimestampSecRequestBody.h"

#define BODY_LENGTH 10

SetNTPTimestampSecRequestMessage::SetNTPTimestampSecRequestMessage(uint32_t seconds):Message(
		new CommandHeader(BODY_LENGTH), new SetNTPTimestampSecRequestBody(seconds)) {
}
