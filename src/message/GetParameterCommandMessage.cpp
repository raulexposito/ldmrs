#include "hdr/GetParameterCommandMessage.h"

#include "../header/hdr/CommandHeader.h"
#include "../body/hdr/GetParameterCommandBody.h"

#define BODY_LENGTH 6

GetParameterCommandMessage::GetParameterCommandMessage(ParameterEnum parameter):Message(
		new CommandHeader(BODY_LENGTH), new GetParameterCommandBody(parameter)) {}
