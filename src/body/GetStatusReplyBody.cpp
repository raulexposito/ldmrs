#include "hdr/GetStatusReplyBody.h"
#include "enum/ParameterEnum.h"

#define CODE_PREFFIX 0x01
#define CODE_SUFFIX 0x00
#define BODY_SIZE 4

// TODO: implementar todos los metodos que devuelven informacion

GetStatusReplyBody::GetStatusReplyBody():
			Body(BODY_SIZE, CODE_PREFFIX, CODE_SUFFIX) {}

GetStatusReplyBody::GetStatusReplyBody(int bodySize, uint8_t * bodyBytes):
		Body(bodySize, bodyBytes) {
}

BodyTypeEnum GetStatusReplyBody::getBodyType() {
	return GET_STATUS;
}
