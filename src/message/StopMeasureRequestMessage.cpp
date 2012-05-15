#include "hdr/StopMeasureRequestMessage.h"

#include "../header/hdr/CommandHeader.h"
#include "../body/hdr/StopMeasureRequestBody.h"

#define BODY_LENGTH 4

StopMeasureRequestMessage::StopMeasureRequestMessage() {
 	header = new CommandHeader(BODY_LENGTH);
	body = new StopMeasureRequestBody();
}
