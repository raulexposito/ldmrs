#include "hdr/StartMeasureMessage.h"

#include "../header/hdr/CommandHeader.h"
#include "../body/hdr/StartMeasureBody.h"

#define BODY_LENGTH 4

StartMeasureMessage::StartMeasureMessage():Message(
		new CommandHeader(BODY_LENGTH), new StartMeasureBody()) {
}
