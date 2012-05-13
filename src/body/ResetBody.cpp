#include "hdr/ResetBody.h"

#define CODE_PREFFIX 0x00
#define CODE_SUFFIX 0x00
#define BODY_SIZE 4

ResetBody::ResetBody():
			Body(BODY_SIZE, CODE_PREFFIX, CODE_SUFFIX) {}
