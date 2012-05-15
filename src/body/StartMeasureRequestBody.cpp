#include "hdr/StartMeasureRequestBody.h"

#define CODE_PREFFIX 0x20
#define CODE_SUFFIX 0x00
#define BODY_SIZE 4

StartMeasureRequestBody::StartMeasureRequestBody():
			Body(BODY_SIZE, CODE_PREFFIX, CODE_SUFFIX) {}
