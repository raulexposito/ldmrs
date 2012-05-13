#include "hdr/SaveConfigMessage.h"

#include "../header/hdr/CommandHeader.h"
#include "../body/hdr/SaveConfigBody.h"

#define BODY_LENGTH 4

SaveConfigMessage::SaveConfigMessage() {
 	header = new CommandHeader(BODY_LENGTH);
	body = new SaveConfigBody();
}
