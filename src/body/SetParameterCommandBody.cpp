#include "hdr/SetParameterCommandBody.h"
#include "enum/ParameterEnum.h"
#include "util/hdr/ParameterConverter.h"

#define CODE_PREFFIX 0x10
#define CODE_SUFFIX 0x00
#define BODY_SIZE 10
#define PARAMETER_CODE_PREFFIX_POSITION 4
#define PARAMETER_CODE_SUFFIX_POSITION 5
#define VALUE_POSITION 6

SetParameterCommandBody::SetParameterCommandBody(ParameterEnum parameter, uint32_t value):
			Body(BODY_SIZE, CODE_PREFFIX, CODE_SUFFIX) {

	switch (parameter) {
		case IP_ADDRESS:
			addParameterCode(IP_ADDRESS);
			addUINT32ParameterValue(value);
			break;
		case TCP_PORT:
			addParameterCode(TCP_PORT);
			addUINT32ParameterValue(value);
			break;
		case SUBNET_MASK:
			addParameterCode(SUBNET_MASK);
			addUINT32ParameterValue(value);
			break;
		case STANDARD_GATEWAY:
			addParameterCode(STANDARD_GATEWAY);
			addUINT32ParameterValue(value);
			break;
		case DATA_OUTPUT_FLAG:
			addParameterCode(DATA_OUTPUT_FLAG);
			addUINT16ParameterValue(value);
			break;
		case START_ANGLE:
			addParameterCode(START_ANGLE);
			addUINT16ParameterValue(value);
			break;
		case END_ANGLE:
			addParameterCode(END_ANGLE);
			addUINT16ParameterValue(value);
			break;
		case SCAN_FRECUENCY:
			addParameterCode(SCAN_FRECUENCY);
			addUINT16ParameterValue(value);
			break;
		case SYNC_ANGLE_OFFSET:
			addParameterCode(SYNC_ANGLE_OFFSET);
			addUINT16ParameterValue(value);
			break;
		case ANGULAR_RESOLUTION_TYPE:
			addParameterCode(ANGULAR_RESOLUTION_TYPE);
			addUINT16ParameterValue(value);
			break;
		case ANGLE_TICKS_PER_ROTATION:
			addParameterCode(ANGLE_TICKS_PER_ROTATION);
			addUINT16ParameterValue(value);
			break;
	}
}

void SetParameterCommandBody::addParameterCode(ParameterEnum parameter) {
	ParameterConverter::getInstance()->parameterToHex(
			parameter,
			bytes[PARAMETER_CODE_PREFFIX_POSITION],
			bytes[PARAMETER_CODE_SUFFIX_POSITION]);
}

void SetParameterCommandBody::addUINT32ParameterValue(uint32_t value) {
	bytes[VALUE_POSITION] = (value & 0xff000000) >> 24;
	bytes[VALUE_POSITION + 1] = (value & 0x00ff0000) >> 16;
	bytes[VALUE_POSITION + 2] = (value & 0x0000ff00) >> 8;
	bytes[VALUE_POSITION + 3] = (value & 0x000000ff);
}

void SetParameterCommandBody::addUINT16ParameterValue(uint32_t value) {
	bytes[VALUE_POSITION] = (value & 0x00000000);
	bytes[VALUE_POSITION + 1] = (value & 0x00000000);
	bytes[VALUE_POSITION + 2] = (value & 0x0000ff00) >> 8;
	bytes[VALUE_POSITION + 3] = (value & 0x000000ff);
}

int SetParameterCommandBody::getAmountBytes() {
	return BODY_SIZE;
}

bool SetParameterCommandBody::isSetParameterCommandBody() {
	return true;
}

std::string SetParameterCommandBody::asText() {
	std::stringstream text;
	text << "SET PARAMETER COMMAND" << ":";
	text << getAmountBytes() << ":";
	// TODO: mostrar el parametro
	// TODO: mostrar el valor del parametro
	return text.str();
}
