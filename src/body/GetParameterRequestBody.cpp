#include "hdr/GetParameterRequestBody.h"
#include "enum/ParameterEnum.h"
#include "util/hdr/ParameterConverter.h"

#define CODE_PREFFIX 0x11
#define CODE_SUFFIX 0x00
#define BODY_SIZE 6
#define PARAMETER_CODE_PREFFIX_POSITION 4
#define PARAMETER_CODE_SUFFIX_POSITION 5

GetParameterRequestBody::GetParameterRequestBody(ParameterEnum parameter):
			Body(BODY_SIZE, CODE_PREFFIX, CODE_SUFFIX) {
	addParameterCode(parameter);
}

void GetParameterRequestBody::addParameterCode(ParameterEnum parameter) {
	ParameterConverter::getInstance()->parameterToHex(
			parameter,
			bytes[PARAMETER_CODE_PREFFIX_POSITION],
			bytes[PARAMETER_CODE_SUFFIX_POSITION]);
}

int GetParameterRequestBody::getAmountBytes() {
	return BODY_SIZE;
}
