#include "hdr/StartMeasureBody.h"

#define CODE_PREFFIX 0x20
#define CODE_SUFFIX 0x00
#define BODY_SIZE 4

StartMeasureBody::StartMeasureBody():
			Body(BODY_SIZE, CODE_PREFFIX, CODE_SUFFIX) {}

BodyTypeEnum StartMeasureBody::getBodyType() {
	return START_MEASURE;
}
