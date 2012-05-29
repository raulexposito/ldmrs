#include "hdr/SetNTPTimestampSecReplyBody.h"

#define CODE_PREFFIX 0x30
#define CODE_SUFFIX 0x00
#define BODY_SIZE 4

SetNTPTimestampSecReplyBody::SetNTPTimestampSecReplyBody(uint32_t seconds):
			Body(BODY_SIZE, CODE_PREFFIX, CODE_SUFFIX) {

	// TODO: tratar los segundos
}

BodyTypeEnum SetNTPTimestampSecReplyBody::getBodyType() {
	return SET_NTP_TIMESTAMP_SEC;
}
