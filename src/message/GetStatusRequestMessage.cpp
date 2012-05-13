#include "hdr/GetStatusRequestMessage.h"

#include "../header/hdr/CommandHeader.h"
#include "../body/hdr/GetStatusRequestBody.h"

#define BODY_LENGTH 4

GetStatusRequestMessage::GetStatusRequestMessage() {
 	header = new CommandHeader(BODY_LENGTH);
	body = new GetStatusRequestBody();
}
