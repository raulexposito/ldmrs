#include "hdr/StartMeasureRequestMessage.h"

#include "../header/hdr/CommandHeader.h"
#include "../body/hdr/StartMeasureRequestBody.h"

#define BODY_LENGTH 4

StartMeasureRequestMessage::StartMeasureRequestMessage():Message(
		new CommandHeader(BODY_LENGTH), new StartMeasureRequestBody()) {
}
