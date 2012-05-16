#include "hdr/SetParameterRequestMessage.h"

#include "../header/hdr/CommandHeader.h"
#include "../body/hdr/SetParameterRequestBody.h"

#define BODY_LENGTH 10

SetParameterRequestMessage::SetParameterRequestMessage(ParameterEnum parameter, uint32_t value):Message(
		new CommandHeader(BODY_LENGTH), new SetParameterRequestBody(parameter, value)) {
}
