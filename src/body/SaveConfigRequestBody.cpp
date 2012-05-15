#include "hdr/SaveConfigRequestBody.h"

#define CODE_PREFFIX 0x04
#define CODE_SUFFIX 0x00
#define BODY_SIZE 4

SaveConfigRequestBody::SaveConfigRequestBody():
			Body(BODY_SIZE, CODE_PREFFIX, CODE_SUFFIX) {}
