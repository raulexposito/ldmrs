#include "hdr/GetStatusRequestBody.h"

#define CODE_PREFFIX 0x01
#define CODE_SUFFIX 0x00
#define BODY_SIZE 4

GetStatusRequestBody::GetStatusRequestBody():
			Body(BODY_SIZE, CODE_PREFFIX, CODE_SUFFIX) {}