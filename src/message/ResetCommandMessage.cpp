#include "hdr/ResetCommandMessage.h"

#include "../header/hdr/CommandHeader.h"
#include "../body/hdr/ResetCommandBody.h"

#define BODY_LENGTH 4

ResetCommandMessage::ResetCommandMessage():Message(new CommandHeader(BODY_LENGTH), new ResetCommandBody()) {
}
