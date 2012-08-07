#include "hdr/StopMeasureBody.h"

#define CODE_PREFFIX 0x21
#define CODE_SUFFIX 0x00
#define BODY_SIZE 4

StopMeasureBody::StopMeasureBody():
			Body(BODY_SIZE, CODE_PREFFIX, CODE_SUFFIX) {}

// TODO: isXXX2
BodyTypeEnum StopMeasureBody::getBodyType() {
	return STOP_MEASURE;
}
