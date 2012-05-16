#include "hdr/StopMeasureRequestMessage.h"

#include "../header/hdr/CommandHeader.h"
#include "../body/hdr/StopMeasureRequestBody.h"

#define BODY_LENGTH 4

StopMeasureRequestMessage::StopMeasureRequestMessage():Message(
		new CommandHeader(BODY_LENGTH), new StopMeasureRequestBody()) {
}
