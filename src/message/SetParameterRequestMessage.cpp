#include "hdr/SetParameterRequestMessage.h"

#include "../header/hdr/CommandHeader.h"
#include "../body/hdr/SetParameterRequestBody.h"

#define BODY_LENGTH 10

SetParameterRequestMessage::SetParameterRequestMessage(ParameterEnum parameter, uint32_t value) {
 	header = new CommandHeader(BODY_LENGTH);
	body = new SetParameterRequestBody(parameter, value);
}
