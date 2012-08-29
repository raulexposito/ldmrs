#include "hdr/BodyFactory.h"
#include "../hdr/ResetCommandBody.h"
#include "../hdr/GetStatusCommandReplyBody.h"
#include "../hdr/SaveConfigCommandBody.h"
#include "../hdr/GetParameterCommandReplyBody.h"
#include "../hdr/SetNTPTimestampSecCommandReplyBody.h"
#include "../hdr/SetNTPTimestampFracSecCommandReplyBody.h"

BodyFactory* BodyFactory::instance = 0;

BodyFactory* BodyFactory::getInstance() {
   if (!instance)
	   instance = new BodyFactory;
   return instance;
}

Body* BodyFactory::generateBody (int bodySize, uint8_t * bodyBytes) {
	Body * body = new Body(bodySize, bodyBytes);
	return body;
}
