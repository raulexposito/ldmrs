#include "hdr/StopMeasureCommandMessage.h"

#include "../header/hdr/CommandHeader.h"
#include "../body/hdr/StopMeasureCommandBody.h"

#define BODY_LENGTH 4

StopMeasureCommandMessage::StopMeasureCommandMessage():Message(
		new CommandHeader(BODY_LENGTH), new StopMeasureCommandBody()) {
}
