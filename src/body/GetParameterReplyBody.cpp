#include "hdr/GetParameterReplyBody.h"
#include "enum/ParameterEnum.h"
#include "util/hdr/ParameterConverter.h"

#define CODE_PREFFIX 0x11
#define CODE_SUFFIX 0x00
#define BODY_SIZE 6

// TODO: implementar
GetParameterReplyBody::GetParameterReplyBody(ParameterEnum parameter):
			Body(BODY_SIZE, CODE_PREFFIX, CODE_SUFFIX) {
}

BodyTypeEnum GetParameterReplyBody::getBodyType() {
	return GET_PARAMETER;
}
