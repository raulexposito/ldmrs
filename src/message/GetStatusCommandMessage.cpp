#include "hdr/GetStatusCommandMessage.h"

#include "../header/hdr/CommandHeader.h"
#include "../body/hdr/GetStatusCommandBody.h"

#define BODY_LENGTH 4

GetStatusCommandMessage::GetStatusCommandMessage():Message(
		new CommandHeader(BODY_LENGTH), new GetStatusCommandBody()) {}
