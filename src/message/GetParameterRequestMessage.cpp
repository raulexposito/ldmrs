#include "hdr/GetParameterRequestMessage.h"

#include "../header/hdr/CommandHeader.h"
#include "../body/hdr/GetParameterRequestBody.h"

#define BODY_LENGTH 8

GetParameterRequestMessage::GetParameterRequestMessage(ParameterEnum parameter):Message(
		new CommandHeader(BODY_LENGTH), new GetParameterRequestBody(parameter)) {}
