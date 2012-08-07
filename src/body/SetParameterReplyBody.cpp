#include "hdr/SetParameterReplyBody.h"
#include "enum/ParameterEnum.h"
#include "util/hdr/ParameterConverter.h"

#define CODE_PREFFIX 0x10
#define CODE_SUFFIX 0x00
#define BODY_SIZE 10

SetParameterReplyBody::SetParameterReplyBody(int bodySize, uint8_t * bodyBytes):
		Body(bodySize, bodyBytes) {
}

// TODO: isXXX2()
BodyTypeEnum SetParameterReplyBody::getBodyType() {
	return SET_PARAMETER;
}
