#include "hdr/SetNTPTimestampFracSecRequestBody.h"

#define CODE_PREFFIX 0x31
#define CODE_SUFFIX 0x00
#define BODY_SIZE 4

SetNTPTimestampFracSecRequestBody::SetNTPTimestampFracSecRequestBody(uint32_t frac_seconds):
			Body(BODY_SIZE, CODE_PREFFIX, CODE_SUFFIX) {

	// TODO: tratar las fracciones de segundo
}
