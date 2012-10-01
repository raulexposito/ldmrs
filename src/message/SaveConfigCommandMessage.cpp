#include "hdr/SaveConfigCommandMessage.h"

#include "../header/hdr/CommandHeader.h"
#include "../body/hdr/SaveConfigCommandBody.h"

#define BODY_LENGTH 4

SaveConfigCommandMessage::SaveConfigCommandMessage():Message(new CommandHeader(BODY_LENGTH), new SaveConfigCommandBody()) {
}
