#include "hdr/SaveConfigRequestMessage.h"

#include "../header/hdr/CommandHeader.h"
#include "../body/hdr/SaveConfigRequestBody.h"

#define BODY_LENGTH 4

SaveConfigRequestMessage::SaveConfigRequestMessage():Message(new CommandHeader(BODY_LENGTH), new SaveConfigRequestBody()) {
}
