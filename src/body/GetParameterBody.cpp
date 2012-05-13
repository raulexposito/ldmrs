#include "hdr/GetParameterBody.h"
#include "enum/ParameterEnum.h"
#include "util/hdr/ParameterConverter.h"

#define CODE_PREFFIX 0x11
#define CODE_SUFFIX 0x00
#define BODY_SIZE 6
#define PARAMETER_CODE_PREFFIX_POSITION 4
#define PARAMETER_CODE_SUFFIX_POSITION 5

/**
 * TODO: en la pagina 11 hablan del mensaje de vuelta, hay que implementarlo
 */

GetParameterBody::GetParameterBody(ParameterEnum parameter):
			Body(BODY_SIZE, CODE_PREFFIX, CODE_SUFFIX) {
	addParameterCode(parameter);
}

void GetParameterBody::addParameterCode(ParameterEnum parameter) {

	ParameterConverter::getInstance()->parameterToHex(
			parameter,
			bytes[PARAMETER_CODE_PREFFIX_POSITION],
			bytes[PARAMETER_CODE_SUFFIX_POSITION]);
}
