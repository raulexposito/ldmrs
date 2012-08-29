#include "hdr/Message.h"

#include <iostream>		// para 'cout'
#include <iomanip>		// para formateo de cout
using namespace std;	// para formateo de cout

#define HEADER_SIZE 24

#define TYPE_FIRST_POSITION 0
#define TYPE_SECOND_POSITION 1

#define COMMAND_REPLY_PARAMETER_TYPE_FIRST_POSITION 2
#define COMMAND_REPLY_PARAMETER_TYPE_SECOND_POSITION 3

#define COMMAND_REPLY_PARAMETER_VALUE_INIT_POSITION 4
#define COMMAND_REPLY_PARAMETER_VALUE_END_POSITION 7

#define COMMAND_PARAMETER_TYPE_FIRST_POSITION 4
#define COMMAND_PARAMETER_TYPE_SECOND_POSITION 5

#define COMMAND_PARAMETER_VALUE_INIT_POSITION 6
#define COMMAND_PARAMETER_VALUE_END_POSITION 9

#define TYPE_COMMAND false
#define TYPE_COMMAND_REPLY true

#define ADDRESS true
#define NUMBER false

#define FIRST_POINT_MEASUREMENT_POSITION 44
#define POINT_MEASUREMENT_LENGHT 10

Message::Message(Header* header, Body* body) {
	this->header = header;
	this->body = body;
	this->messageSize = HEADER_SIZE + this->header->getBodySize();
	this->bytes = new uint8_t[messageSize];
}

Message::~Message() {
	delete header;
	delete body;
	delete bytes;
}

Header * Message::getHeader() {
	return header;
}

Body * Message::getBody() {
	return body;
}

uint8_t* Message::getBytesInRaw() {
	int i;
	for (i = 0; i < HEADER_SIZE; i++) {
		bytes[i] = this->header->getBytesInRaw()[i];
	}
	for (i = 0; i < body->getAmountBytes(); i++) {
		bytes[HEADER_SIZE + i] = this->body->getBytesInRaw()[i];
	}
	return bytes;
}

bool Message::isScanDataMessage() {
	return this->header->isScanDataHeader();
}

bool Message::isErrorAndWarningMessage() {
	return this->header->isErrorAndWarningHeader();
}

bool Message::isCommandMessage() {
	return this->header->isCommandHeader();
}

bool Message::isCommandReplyMessage() {
	return this->header->isCommandReplyHeader();
}

bool Message::isGetParameterCommandMessage() {
	return this->body->isGetParameterCommandBody();
}

bool Message::isGetParameterCommandReplyMessage() {
	return this->body->isGetParameterCommandReplyBody();
}

bool Message::isGetStatusCommandMessage() {
	return this->body->isGetStatusCommandBody();
}

bool Message::isGetStatusCommandReplyMessage() {
	return this->body->isGetStatusCommandReplyBody();
}

bool Message::isResetCommandMessage() {
	return this->body->isResetCommandBody();
}

bool Message::isSaveConfigCommandMessage() {
	return this->body->isSaveConfigCommandBody();
}

bool Message::isSetNTPTimestampFracSecCommandMessage() {
	return this->body->isSetNTPTimestampFracSecCommandBody();
}

bool Message::isSetNTPTimestampFracSecCommandReplyMessage() {
	return this->body->isSetNTPTimestampFracSecCommandReplyBody();
}

bool Message::isSetNTPTimestampSecCommandMessage() {
	return this->body->isSetNTPTimestampSecCommandBody();
}

bool Message::isSetNTPTimestampSecCommandReplyMessage() {
	return this->body->isSetNTPTimestampSecCommandReplyBody();
}

bool Message::isSetParameterCommandMessage() {
	return this->body->isSetParameterCommandBody();
}

bool Message::isSetParameterCommandReplyMessage() {
	return this->body->isSetParameterCommandReplyBody();
}

bool Message::isStartMeasureCommandMessage() {
	return this->body->isStartMeasureCommandBody();
}

bool Message::isStopMeasureCommandMessage() {
	return this->body->isStopMeasureCommandBody();
}

int Message::getAmountBytes() {
	return HEADER_SIZE + this->header->getBodySize();
}

void Message::showHeaderDataType(HeaderTypeEnum headerType, Body* body) {
	switch (headerType) {
		case SCAN_DATA: cout << "SCAN DATA"; showScanData(body); break;
		case ERRORS_AND_WARNINGS: cout << "ERRORS AND WARNINGS"; showErrorsAndWarnings(body); break;
		case COMMAND: cout << "COMMAND"; showHeaderSubDataType(body, TYPE_COMMAND); break;
		case COMMAND_REPLY: cout << "COMMAND REPLY"; showHeaderSubDataType(body, TYPE_COMMAND_REPLY); break;
	}
}

void Message::showHeaderSubDataType(Body* body, bool isCommandReply) {
	if (body->getBytesInRaw()[TYPE_FIRST_POSITION] == 0x00 && body->getBytesInRaw()[TYPE_SECOND_POSITION]  == 0x00) {
		cout << endl << "\tsubtype: RESET";
	}
	else if (body->getBytesInRaw()[TYPE_FIRST_POSITION] == 0x01 && body->getBytesInRaw()[TYPE_SECOND_POSITION]  == 0x00) {
		cout << endl << "\tsubtype: GET STATUS";
		if (isCommandReply) {
			showGetStatus(body);
		}
	}
	else if (body->getBytesInRaw()[TYPE_FIRST_POSITION] == 0x04 && body->getBytesInRaw()[TYPE_SECOND_POSITION]  == 0x00) {
		cout << endl << "\tsubtype: SAVE CONFIG";
	}
	else if (body->getBytesInRaw()[TYPE_FIRST_POSITION] == 0x10 && body->getBytesInRaw()[TYPE_SECOND_POSITION]  == 0x00) {
		cout << endl << "\tsubtype: SET PARAMETER";
		bool isAddress = showParameterType(body, COMMAND_PARAMETER_TYPE_FIRST_POSITION, COMMAND_PARAMETER_TYPE_SECOND_POSITION);
		showParameterValue(body, COMMAND_PARAMETER_VALUE_INIT_POSITION, COMMAND_PARAMETER_VALUE_END_POSITION, isAddress);
	}
	else if (body->getBytesInRaw()[TYPE_FIRST_POSITION] == 0x11 && body->getBytesInRaw()[TYPE_SECOND_POSITION]  == 0x00) {
		cout << endl << "\tsubtype: GET PARAMETER";
		if (isCommandReply) {
			bool isAddress = showParameterType(body, COMMAND_REPLY_PARAMETER_TYPE_FIRST_POSITION, COMMAND_REPLY_PARAMETER_TYPE_SECOND_POSITION);
			showParameterValue(body, COMMAND_REPLY_PARAMETER_VALUE_INIT_POSITION, COMMAND_REPLY_PARAMETER_VALUE_END_POSITION, isAddress);
		} else {
			showParameterType(body, COMMAND_PARAMETER_TYPE_FIRST_POSITION, COMMAND_PARAMETER_TYPE_SECOND_POSITION);
		}
	}
	else if (body->getBytesInRaw()[TYPE_FIRST_POSITION] == 0x20 && body->getBytesInRaw()[TYPE_SECOND_POSITION]  == 0x00) {
		cout << endl << "\tsubtype: START MEASURE";
	}
	else if (body->getBytesInRaw()[TYPE_FIRST_POSITION] == 0x21 && body->getBytesInRaw()[TYPE_SECOND_POSITION]  == 0x00) {
		cout << endl << "\tsubtype: STOP MEASURE";
	}
	else if (body->getBytesInRaw()[TYPE_FIRST_POSITION] == 0x30 && body->getBytesInRaw()[TYPE_SECOND_POSITION]  == 0x00) {
		cout << endl << "\tsubtype: SET NTP TIMESTAMP SEC";
	}
	else if (body->getBytesInRaw()[TYPE_FIRST_POSITION] == 0x31 && body->getBytesInRaw()[TYPE_SECOND_POSITION]  == 0x00) {
		cout << endl << "\tsubtype: SET NTP TIMESTAMP FRAC SEC";
	}
}

bool Message::showParameterType(Body* body, int firstPosition, int secondPosition) {
	if (body->getBytesInRaw()[firstPosition] == 0x00 && body->getBytesInRaw()[secondPosition]  == 0x10) {
		cout << endl << "\tparameter: IP ADDRESS";
		return ADDRESS;
	}
	else if (body->getBytesInRaw()[firstPosition] == 0x01 && body->getBytesInRaw()[secondPosition]  == 0x10) {
		cout << endl << "\tparameter: TCP PORT";
	}
	else if (body->getBytesInRaw()[firstPosition] == 0x02 && body->getBytesInRaw()[secondPosition]  == 0x10) {
		cout << endl << "\tparameter: SUBNET MASK";
		return ADDRESS;
	}
	else if (body->getBytesInRaw()[firstPosition] == 0x03 && body->getBytesInRaw()[secondPosition]  == 0x10) {
		cout << endl << "\tparameter: STANDARD GATEWAY";
		return ADDRESS;
	}
	else if (body->getBytesInRaw()[firstPosition] == 0x12 && body->getBytesInRaw()[secondPosition]  == 0x10) {
		cout << endl << "\tparameter: DATA OUTPUT FLAG";
	}
	else if (body->getBytesInRaw()[firstPosition] == 0x00 && body->getBytesInRaw()[secondPosition]  == 0x11) {
		cout << endl << "\tparameter: START ANGLE";
	}
	else if (body->getBytesInRaw()[firstPosition] == 0x01 && body->getBytesInRaw()[secondPosition]  == 0x11) {
		cout << endl << "\tparameter: END ANGLE";
	}
	else if (body->getBytesInRaw()[firstPosition] == 0x02 && body->getBytesInRaw()[secondPosition]  == 0x11) {
		cout << endl << "\tparameter: SCAN FRECUENCY";
	}
	else if (body->getBytesInRaw()[firstPosition] == 0x03 && body->getBytesInRaw()[secondPosition]  == 0x11) {
		cout << endl << "\tparameter: SYNC ANGLE OFFSET";
	}
	else if (body->getBytesInRaw()[firstPosition] == 0x04 && body->getBytesInRaw()[secondPosition]  == 0x11) {
		cout << endl << "\tparameter: ANGULAR RESOLUTION TYPE";
	}
	return NUMBER;
}

void Message::showParameterValue(Body* body, int initPosition, int endPosition, bool isAddress) {
	cout << endl << "\tvalue: ";
	int i;
	for (i = endPosition; i >= initPosition; i--) {
		cout << setw(2) << setfill('0') << hex << uppercase << (int) body->getBytesInRaw()[i] << " ";
	}
	cout << dec;
	cout << "-> ";

	if (isAddress) {
		for (i = endPosition; i >= initPosition + 1; i--) {
			cout << setfill('0') << (int) body->getBytesInRaw()[i] << ".";
		}
		cout << setfill('0') << (int) body->getBytesInRaw()[initPosition];
	} else {
		int value;
		value = static_cast<int>(body->getBytesInRaw()[endPosition]) * 16777216;
		value += static_cast<int>(body->getBytesInRaw()[endPosition - 1]) * 65536;
		value += static_cast<int>(body->getBytesInRaw()[endPosition - 2]) * 256;
		value += static_cast<int>(body->getBytesInRaw()[endPosition - 3]);
		cout << value;
	}
}

void Message::showGetStatus(Body* body) {

	cout << endl << "\tfirmware: ";
	showHex8(body->getBytesInRaw()[2]);
	showHex8(body->getBytesInRaw()[3]);

	cout << endl << "\tFPGA version: ";
	showHex8(body->getBytesInRaw()[4]);
	showHex8(body->getBytesInRaw()[5]);

	cout << endl << "\tScanner status: ";
	showHex8(body->getBytesInRaw()[6]);
	showHex8(body->getBytesInRaw()[7]);

	cout << endl << "\tScanner status: ";
	showHex8(body->getBytesInRaw()[6]);
	showHex8(body->getBytesInRaw()[7]);
	showHex8(body->getBytesInRaw()[8]);
	showHex8(body->getBytesInRaw()[9]);

	cout << endl << "\tTemperature: ";
	showHex8(body->getBytesInRaw()[12]);
	showHex8(body->getBytesInRaw()[13]);

	cout << endl << "\tSerial number 0: ";
	showHex8(body->getBytesInRaw()[14]);
	showHex8(body->getBytesInRaw()[15]);

	cout << endl << "\tSerial number 1: ";
	showHex8(body->getBytesInRaw()[16]);
	showHex8(body->getBytesInRaw()[17]);

	cout << endl << "\tFPGA timestamp: ";
	showHex8(body->getBytesInRaw()[20]);
	showHex8(body->getBytesInRaw()[21]);
	showHex8(body->getBytesInRaw()[22]);
	showHex8(body->getBytesInRaw()[23]);
	showHex8(body->getBytesInRaw()[24]);
	showHex8(body->getBytesInRaw()[25]);

	cout << endl << "\tDSP timestamp: ";
	showHex8(body->getBytesInRaw()[26]);
	showHex8(body->getBytesInRaw()[27]);
	showHex8(body->getBytesInRaw()[28]);
	showHex8(body->getBytesInRaw()[29]);
	showHex8(body->getBytesInRaw()[30]);
	showHex8(body->getBytesInRaw()[31]);
}

void Message::showHex8(uint8_t uint8) {
	cout << setw(2) << setfill('0') << hex << uppercase << (int) uint8 << " " << dec;
}

void Message::showScanData(Body* body) {
	int scanPoints = (body->getBytesInRaw()[29] * 256) + body->getBytesInRaw()[28];
	cout << endl << "\tscan number: " << (body->getBytesInRaw()[1] * 256) + body->getBytesInRaw()[0];
	cout << endl << "\tscanner status: "; showHex8(body->getBytesInRaw()[3]); showHex8(body->getBytesInRaw()[2]);
	cout << endl << "\tsync phase offset: " << (body->getBytesInRaw()[5] * 256) + body->getBytesInRaw()[4];
	cout << endl << "\tscan start time NTP: <TODO>";
	cout << endl << "\tscan end time NTP: <TODO>";
	cout << endl << "\tangle ticks per rotation: " << (body->getBytesInRaw()[23] * 256) + body->getBytesInRaw()[22];
	cout << endl << "\tstart angle: " << (body->getBytesInRaw()[25] * 256) + body->getBytesInRaw()[24];
	cout << endl << "\tend angle: " << (body->getBytesInRaw()[27] * 256) + body->getBytesInRaw()[26];
	cout << endl << "\tscan points: " << scanPoints;
	int i = 0;
	int pointBodyPosition = FIRST_POINT_MEASUREMENT_POSITION;
	for (i = 0; i < scanPoints; i++) {
		showPointMeasurement(i, pointBodyPosition, body);
		pointBodyPosition += POINT_MEASUREMENT_LENGHT;
	}
}

void Message::showPointMeasurement(int number, int pointBodyPosition, Body* body) {
	cout << endl << "\tmeaurement point " << number;
	cout << endl << "\t\tlayer and echo: ";showHex8(body->getBytesInRaw()[pointBodyPosition]);
	cout << endl << "\t\tflags: ";showHex8(body->getBytesInRaw()[pointBodyPosition + 1]);
	cout << endl << "\t\thorizontal angle: " << (body->getBytesInRaw()[pointBodyPosition + 3] * 256) + body->getBytesInRaw()[pointBodyPosition + 2];
	cout << endl << "\t\tradial distance: " << (body->getBytesInRaw()[pointBodyPosition + 5] * 256) + body->getBytesInRaw()[pointBodyPosition + 4];
	cout << endl << "\t\techo pulse width: " << (body->getBytesInRaw()[pointBodyPosition + 7] * 256) + body->getBytesInRaw()[pointBodyPosition + 6];
}

void Message::showErrorsAndWarnings(Body* body) {

	// Error register 1
	if (body->getBytesInRaw()[0] & 0x00000001) { cout << endl << "\tmessage: Contact support"; }
	if (body->getBytesInRaw()[0] & 0x00000010) { cout << endl << "\tmessage: Contact support"; }
	if (body->getBytesInRaw()[0] & 0x00000100) { cout << endl << "\tmessage: Scan buffered transmitted incompletely, decrease scan resolution/frecuency/range; contact support"; }
	if (body->getBytesInRaw()[0] & 0x00001000) { cout << endl << "\tmessage: Scan buffer overflow, decrease scan resolution/frecuency/range; contact support"; }
	if (body->getBytesInRaw()[0] & 0x00010000) { cout << endl << "\tmessage: Contact support"; }
	if (body->getBytesInRaw()[0] & 0x00100000) { cout << endl << "\tmessage: Reserved"; }
	if (body->getBytesInRaw()[0] & 0x01000000) { cout << endl << "\tmessage: Reserved"; }
	if (body->getBytesInRaw()[0] & 0x10000000) { cout << endl << "\tmessage: Reserved"; }

	if (body->getBytesInRaw()[1] & 0x00000001) { cout << endl << "\tmessage: ADP Under Temperature, provide heating"; }
	if (body->getBytesInRaw()[1] & 0x00000010) { cout << endl << "\tmessage: ADP Over Temperature, provide cooling"; }
	if ((body->getBytesInRaw()[1] & 0x00000010) && (body->getBytesInRaw()[1] & 0x00000001)) { cout << endl << "\tmessage: APD Temperature Sensor defect, contact support";}
	if (body->getBytesInRaw()[1] & 0x00000010) { cout << endl << "\tmessage: Contact support"; }
	if (body->getBytesInRaw()[1] & 0x00001000) { cout << endl << "\tmessage: Contact support"; }
	if (body->getBytesInRaw()[1] & 0x00010000) { cout << endl << "\tmessage: Contact support"; }
	if (body->getBytesInRaw()[1] & 0x00100000) { cout << endl << "\tmessage: Contact support"; }
	if (body->getBytesInRaw()[1] & 0x01000000) { cout << endl << "\tmessage: Reserved"; }
	if (body->getBytesInRaw()[1] & 0x10000000) { cout << endl << "\tmessage: Reserved"; }

	// Error register 2
	if (body->getBytesInRaw()[2] & 0x00000001) { cout << endl << "\tmessage: Contact support"; }
	if (body->getBytesInRaw()[2] & 0x00000010) { cout << endl << "\tmessage: Contact support"; }
	if (body->getBytesInRaw()[2] & 0x00000100) { cout << endl << "\tmessage: Contact support"; }
	if (body->getBytesInRaw()[2] & 0x00001000) { cout << endl << "\tmessage: Contact support"; }
	if (body->getBytesInRaw()[2] & 0x00010000) { cout << endl << "\tmessage: Incorrect configuration data, load correct configuration values"; }
	if (body->getBytesInRaw()[2] & 0x00100000) { cout << endl << "\tmessage: Configuration contains incorrect parameters, load correct configuration values"; }
	if (body->getBytesInRaw()[2] & 0x01000000) { cout << endl << "\tmessage: Data processing timeout, decrease scan resolutiuon or scan frecuency"; }
	if (body->getBytesInRaw()[2] & 0x10000000) { cout << endl << "\tmessage: Contact support"; }
	if (body->getBytesInRaw()[2] & 0x00000001) { cout << endl << "\tmessage: Reserved"; }
	if (body->getBytesInRaw()[2] & 0x00000010) { cout << endl << "\tmessage: Reserved"; }
	if (body->getBytesInRaw()[2] & 0x00000100) { cout << endl << "\tmessage: Reserved"; }
	if (body->getBytesInRaw()[2] & 0x00001000) { cout << endl << "\tmessage: Reserved"; }
	if (body->getBytesInRaw()[2] & 0x00010000) { cout << endl << "\tmessage: Reserved"; }
	if (body->getBytesInRaw()[2] & 0x00100000) { cout << endl << "\tmessage: Reserved"; }
	if (body->getBytesInRaw()[2] & 0x01000000) { cout << endl << "\tmessage: Reserved"; }
	if (body->getBytesInRaw()[2] & 0x10000000) { cout << endl << "\tmessage: Reserved"; }

	// Warning register 1
	if (body->getBytesInRaw()[4] & 0x00000001) { cout << endl << "\tmessage: Internal communication error"; }
	if (body->getBytesInRaw()[4] & 0x00000010) { cout << endl << "\tmessage: Internal warning"; }
	if (body->getBytesInRaw()[4] & 0x00000100) { cout << endl << "\tmessage: Internal warning"; }
	if (body->getBytesInRaw()[4] & 0x00001000) { cout << endl << "\tmessage: Warning temperature very low"; }
	if (body->getBytesInRaw()[4] & 0x00010000) { cout << endl << "\tmessage: Warning temperature very high"; }
	if (body->getBytesInRaw()[4] & 0x00100000) { cout << endl << "\tmessage: Internal warning"; }
	if (body->getBytesInRaw()[4] & 0x01000000) { cout << endl << "\tmessage: Internal warning"; }
	if (body->getBytesInRaw()[4] & 0x10000000) { cout << endl << "\tmessage: Synchronization error, check synchronization and scan frecuency"; }
	if (body->getBytesInRaw()[5] & 0x00000001) { cout << endl << "\tmessage: Reserved"; }
	if (body->getBytesInRaw()[5] & 0x00000010) { cout << endl << "\tmessage: Reserved"; }
	if (body->getBytesInRaw()[5] & 0x00000100) { cout << endl << "\tmessage: Reserved"; }
	if (body->getBytesInRaw()[5] & 0x00001000) { cout << endl << "\tmessage: Reserved"; }
	if (body->getBytesInRaw()[5] & 0x00010000) { cout << endl << "\tmessage: Reserved"; }
	if (body->getBytesInRaw()[5] & 0x00100000) { cout << endl << "\tmessage: Reserved"; }
	if (body->getBytesInRaw()[5] & 0x01000000) { cout << endl << "\tmessage: Reserved"; }
	if (body->getBytesInRaw()[5] & 0x10000000) { cout << endl << "\tmessage: Reserved"; }

	// Warning register 2
	if (body->getBytesInRaw()[6] & 0x00000001) { cout << endl << "\tmessage: Reserved"; }
	if (body->getBytesInRaw()[6] & 0x00000010) { cout << endl << "\tmessage: Ethernet Interface blocked, check Ethernet connection"; }
	if (body->getBytesInRaw()[6] & 0x00001000) { cout << endl << "\tmessage: Contact support"; }
	if (body->getBytesInRaw()[6] & 0x00010000) { cout << endl << "\tmessage: Error receiving Ethernet data, check Ethernet conection/data"; }
	if (body->getBytesInRaw()[6] & 0x00100000) { cout << endl << "\tmessage: Incorrect or forbidden command received, check command"; }
	if (body->getBytesInRaw()[6] & 0x01000000) { cout << endl << "\tmessage: Memory access failure, restart LD-MRS, contact support"; }
	if (body->getBytesInRaw()[6] & 0x10000000) { cout << endl << "\tmessage: Reserved"; }
	if (body->getBytesInRaw()[7] & 0x00000001) { cout << endl << "\tmessage: Reserved"; }
	if (body->getBytesInRaw()[7] & 0x00000010) { cout << endl << "\tmessage: Reserved"; }
	if (body->getBytesInRaw()[7] & 0x00000100) { cout << endl << "\tmessage: Reserved"; }
	if (body->getBytesInRaw()[7] & 0x00001000) { cout << endl << "\tmessage: Reserved"; }
	if (body->getBytesInRaw()[7] & 0x00010000) { cout << endl << "\tmessage: Reserved"; }
	if (body->getBytesInRaw()[7] & 0x00100000) { cout << endl << "\tmessage: Reserved"; }
	if (body->getBytesInRaw()[7] & 0x01000000) { cout << endl << "\tmessage: Reserved"; }
	if (body->getBytesInRaw()[7] & 0x10000000) { cout << endl << "\tmessage: Reserved"; }
}

