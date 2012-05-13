#include "hdr/ResetMessage.h"

#include "../header/hdr/CommandHeader.h"
#include "../body/hdr/ResetBody.h"

#define BODY_LENGTH 4

ResetMessage::ResetMessage() {
 	header = new CommandHeader(BODY_LENGTH);
	body = new ResetBody();
}
