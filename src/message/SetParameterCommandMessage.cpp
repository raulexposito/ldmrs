#include "hdr/SetParameterCommandMessage.h"

#include "../header/hdr/CommandHeader.h"

#define BODY_LENGTH 10

SetParameterCommandMessage::SetParameterCommandMessage(ParameterEnum parameter, uint32_t value):Message(
		new CommandHeader(BODY_LENGTH), new SetParameterCommandBody(parameter, value)) {
}
