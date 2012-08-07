#include "hdr/BodyFactory.h"
#include "../hdr/ResetBody.h"
#include "../hdr/GetStatusReplyBody.h"
#include "../hdr/SaveConfigBody.h"
#include "../hdr/SetParameterReplyBody.h"
#include "../hdr/GetParameterReplyBody.h"
#include "../hdr/StartMeasureBody.h"
#include "../hdr/StopMeasureBody.h"
#include "../hdr/SetNTPTimestampSecReplyBody.h"
#include "../hdr/SetNTPTimestampFracSecReplyBody.h"

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
