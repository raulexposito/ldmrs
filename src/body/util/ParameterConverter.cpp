#include "hdr/ParameterConverter.h"

ParameterConverter* ParameterConverter::instance = 0;

ParameterConverter* ParameterConverter::getInstance() {
   if (!instance)
	   instance = new ParameterConverter;

   return instance;
}

void ParameterConverter::parameterToHex(ParameterEnum parameter, uint8_t & preffix, uint8_t & suffix) {
	switch (parameter) {
		case IP_ADDRESS:
			preffix = 0x00;
			suffix = 0x10;
			break;
		case TCP_PORT:
			preffix = 0x01;
			suffix = 0x10;
			break;
		case SUBNET_MASK:
			preffix = 0x02;
			suffix = 0x10;
			break;
		case STANDARD_GATEWAY:
			preffix = 0x03;
			suffix = 0x10;
			break;
		case DATA_OUTPUT_FLAG:
			preffix = 0x12;
			suffix = 0x10;
			break;
		case START_ANGLE:
			preffix = 0x00;
			suffix = 0x11;
			break;
		case END_ANGLE:
			preffix = 0x01;
			suffix = 0x11;
			break;
		case SCAN_FRECUENCY:
			preffix = 0x02;
			suffix = 0x11;
			break;
		case SYNC_ANGLE_OFFSET:
			preffix = 0x03;
			suffix = 0x11;
			break;
		case ANGULAR_RESOLUTION_TYPE:
			preffix = 0x04;
			suffix = 0x11;
			break;
		case ANGLE_TICKS_PER_ROTATION:
			preffix = 0x05;
			suffix = 0x11;
			break;
	}
}

std::string ParameterConverter::parameterToText(ParameterEnum parameter) {
	switch (parameter) {
		case IP_ADDRESS:
			return "IP ADDRESS";
		case TCP_PORT:
			return "TCP PORT";
		case SUBNET_MASK:
			return "SUBNET MASK";
		case STANDARD_GATEWAY:
			return "STANDARD GATEWAY";
		case DATA_OUTPUT_FLAG:
			return "DATA OUTPUT FLAG";
		case START_ANGLE:
			return "START ANGLE";
		case END_ANGLE:
			return "END ANGLE";
		case SCAN_FRECUENCY:
			return "SCAN FRECUENCY";
		case SYNC_ANGLE_OFFSET:
			return "SYNC ANGLE OFFSET";
		case ANGULAR_RESOLUTION_TYPE:
			return "ANGULAR RESOLUTION TYPE";
		case ANGLE_TICKS_PER_ROTATION:
			return "ANGLE TICKS PER ROTATION";
	}
	return "UNKNOWN";
}

