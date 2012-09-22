#include "hdr/GetParameterCommandBody.h"
#include "util/hdr/ParameterConverter.h"

#define CODE_PREFFIX 0x11
#define CODE_SUFFIX 0x00
#define BODY_SIZE 6
#define PARAMETER_CODE_PREFFIX_POSITION 4
#define PARAMETER_CODE_SUFFIX_POSITION 5

GetParameterCommandBody::GetParameterCommandBody(ParameterEnum parameter):
			Body(BODY_SIZE, CODE_PREFFIX, CODE_SUFFIX) {
	this->parameter = parameter;
	addParameterCode(parameter);
}

void GetParameterCommandBody::addParameterCode(ParameterEnum parameter) {
	ParameterConverter::getInstance()->parameterToHex(
			parameter,
			bytes[PARAMETER_CODE_PREFFIX_POSITION],
			bytes[PARAMETER_CODE_SUFFIX_POSITION]);
}

int GetParameterCommandBody::getAmountBytes() {
	return BODY_SIZE;
}

bool GetParameterCommandBody::isGetParameterCommandBody() {
	return true;
}

std::string GetParameterCommandBody::asText() {
	std::stringstream text;
	text << "GET PARAMETER COMMAND -> ";
	text << ParameterConverter::getInstance()->parameterToText(parameter);
	return text.str();
}
