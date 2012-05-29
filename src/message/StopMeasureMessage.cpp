#include "hdr/StopMeasureMessage.h"

#include "../header/hdr/CommandHeader.h"
#include "../body/hdr/StopMeasureBody.h"

#define BODY_LENGTH 4

StopMeasureMessage::StopMeasureMessage():Message(
		new CommandHeader(BODY_LENGTH), new StopMeasureBody()) {
}
