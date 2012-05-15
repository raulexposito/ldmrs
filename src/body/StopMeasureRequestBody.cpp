#include "hdr/StopMeasureRequestBody.h"

#define CODE_PREFFIX 0x21
#define CODE_SUFFIX 0x00
#define BODY_SIZE 4

StopMeasureRequestBody::StopMeasureRequestBody():
			Body(BODY_SIZE, CODE_PREFFIX, CODE_SUFFIX) {}
