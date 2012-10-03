#include "hdr/StartMeasureCommandMessage.h"

#include "../header/hdr/CommandHeader.h"
#include "../body/hdr/StartMeasureCommandBody.h"

#define BODY_LENGTH 4

StartMeasureCommandMessage::StartMeasureCommandMessage():Message(
		new CommandHeader(BODY_LENGTH), new StartMeasureCommandBody()) {
}
