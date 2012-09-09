#include "hdr/GetParameterCommandReplyBody.h"
#include "util/hdr/ParameterConverter.h"
#include <iomanip>

#define COMMAND_REPLY_PARAMETER_TYPE_FIRST_POSITION 2
#define COMMAND_REPLY_PARAMETER_TYPE_SECOND_POSITION 3

#define COMMAND_REPLY_PARAMETER_VALUE_INIT_POSITION 4
#define COMMAND_REPLY_PARAMETER_VALUE_END_POSITION 7

GetParameterCommandReplyBody::GetParameterCommandReplyBody(int bodySize, uint8_t * bodyBytes):
		Body(bodySize, bodyBytes) {
}

bool GetParameterCommandReplyBody::isGetParameterCommandReplyBody() {
	return true;
}

std::string GetParameterCommandReplyBody::asText() {
	std::stringstream text;
	text << "GET PARAMETER COMMAND REPLY" << "[";
	text << getAmountBytes() << "]:";
	if (getBytesInRaw()[COMMAND_REPLY_PARAMETER_TYPE_FIRST_POSITION] == 0x00 && getBytesInRaw()[COMMAND_REPLY_PARAMETER_TYPE_SECOND_POSITION]  == 0x10) {
		text << "IP ADDRESS:";
		text << addAddress();
	}
	else if (getBytesInRaw()[COMMAND_REPLY_PARAMETER_TYPE_FIRST_POSITION] == 0x01 && getBytesInRaw()[COMMAND_REPLY_PARAMETER_TYPE_SECOND_POSITION]  == 0x10) {
		text << "TCP PORT:";
		text << addNumber();
	}
	else if (getBytesInRaw()[COMMAND_REPLY_PARAMETER_TYPE_FIRST_POSITION] == 0x02 && getBytesInRaw()[COMMAND_REPLY_PARAMETER_TYPE_SECOND_POSITION]  == 0x10) {
		text << "SUBNET MASK:";
		text << addAddress();
	}
	else if (getBytesInRaw()[COMMAND_REPLY_PARAMETER_TYPE_FIRST_POSITION] == 0x03 && getBytesInRaw()[COMMAND_REPLY_PARAMETER_TYPE_SECOND_POSITION]  == 0x10) {
		text << "STANDARD GATEWAY:";
		text << addAddress();
	}
	else if (getBytesInRaw()[COMMAND_REPLY_PARAMETER_TYPE_FIRST_POSITION] == 0x12 && getBytesInRaw()[COMMAND_REPLY_PARAMETER_TYPE_SECOND_POSITION]  == 0x10) {
		text << "DATA OUTPUT FLAG:";
		text << addNumber();
	}
	else if (getBytesInRaw()[COMMAND_REPLY_PARAMETER_TYPE_FIRST_POSITION] == 0x00 && getBytesInRaw()[COMMAND_REPLY_PARAMETER_TYPE_SECOND_POSITION]  == 0x11) {
		text << "START ANGLE:";
		text << addNumber();
	}
	else if (getBytesInRaw()[COMMAND_REPLY_PARAMETER_TYPE_FIRST_POSITION] == 0x01 && getBytesInRaw()[COMMAND_REPLY_PARAMETER_TYPE_SECOND_POSITION]  == 0x11) {
		text << "END ANGLE:";
		text << addNumber();
	}
	else if (getBytesInRaw()[COMMAND_REPLY_PARAMETER_TYPE_FIRST_POSITION] == 0x02 && getBytesInRaw()[COMMAND_REPLY_PARAMETER_TYPE_SECOND_POSITION]  == 0x11) {
		text << "SCAN FRECUENCY:";
		text << addNumber();
	}
	else if (getBytesInRaw()[COMMAND_REPLY_PARAMETER_TYPE_FIRST_POSITION] == 0x03 && getBytesInRaw()[COMMAND_REPLY_PARAMETER_TYPE_SECOND_POSITION]  == 0x11) {
		text << "SYNC ANGLE OFFSET:";
		text << addNumber();
	}
	else if (getBytesInRaw()[COMMAND_REPLY_PARAMETER_TYPE_FIRST_POSITION] == 0x04 && getBytesInRaw()[COMMAND_REPLY_PARAMETER_TYPE_SECOND_POSITION]  == 0x11) {
		text << "ANGULAR RESOLUTION TYPE:";
		text << addNumber();
	}
	return text.str();
}

std::string GetParameterCommandReplyBody::addAddress() {
	std::stringstream address;
	int i;
	for (i = COMMAND_REPLY_PARAMETER_VALUE_END_POSITION; i >= COMMAND_REPLY_PARAMETER_VALUE_INIT_POSITION + 1; i--) {
		address << (int) getBytesInRaw()[i] << ".";
	}
	address << (int) getBytesInRaw()[COMMAND_REPLY_PARAMETER_VALUE_INIT_POSITION];
	return address.str();
}

int GetParameterCommandReplyBody::addNumber() {
	int value;
	value = static_cast<int>(getBytesInRaw()[COMMAND_REPLY_PARAMETER_VALUE_END_POSITION]) * 16777216;
	value += static_cast<int>(getBytesInRaw()[COMMAND_REPLY_PARAMETER_VALUE_END_POSITION - 1]) * 65536;
	value += static_cast<int>(getBytesInRaw()[COMMAND_REPLY_PARAMETER_VALUE_END_POSITION - 2]) * 256;
	value += static_cast<int>(getBytesInRaw()[COMMAND_REPLY_PARAMETER_VALUE_END_POSITION - 3]);
	return value;
}

