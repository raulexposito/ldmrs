#include "hdr/SetNTPTimestampFracSecReplyBody.h"

#define CODE_PREFFIX 0x31
#define CODE_SUFFIX 0x00
#define BODY_SIZE 4

SetNTPTimestampFracSecReplyBody::SetNTPTimestampFracSecReplyBody(uint32_t frac_seconds):
			Body(BODY_SIZE, CODE_PREFFIX, CODE_SUFFIX) {
	// TODO: tratar las fracciones de segundo
}

SetNTPTimestampFracSecReplyBody::SetNTPTimestampFracSecReplyBody(int bodySize, uint8_t * bodyBytes):
		Body(bodySize, bodyBytes) {
}

BodyTypeEnum SetNTPTimestampFracSecReplyBody::getBodyType() {
	return SET_NTP_TIMESTAMP_FRACSEC;
}
