#include "hdr/SetNTPTimestampSecRequestMessage.h"

#include "../header/hdr/CommandHeader.h"
#include "../body/hdr/SetNTPTimestampSecRequestBody.h"

#define BODY_LENGTH 10

SetNTPTimestampSecRequestMessage::SetNTPTimestampSecRequestMessage(uint32_t seconds) {
 	header = new CommandHeader(BODY_LENGTH);
	body = new SetNTPTimestampSecRequestBody(seconds);
}
