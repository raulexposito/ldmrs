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

#define FIRST_POINT_MEASUREMENT_POSITION 44
#define POINT_MEASUREMENT_LENGHT 10

Message::Message(Header* header, Body* body) {
	this->header = header;
	this->body = body;
	populateBytes();
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

void Message::showBytes() {
	this->header->showBytes();
	this->body->showBytes();
}

uint8_t* Message::getBytes() {
	return bytes;
}

HeaderTypeEnum Message::getDataType() {
	return this->header->getDataType();
}

int Message::getAmountBytes() {
	return messageSize;
}

void Message::populateBytes() {
	messageSize = HEADER_SIZE + this->body->getAmountBytes();
	bytes = new uint8_t[messageSize];

	int i;
	for (i = 0; i < HEADER_SIZE; i++) {
		bytes[i] = this->header->getBytes()[i];
	}
	for (i = 0; i < body->getAmountBytes(); i++) {
		bytes[HEADER_SIZE + i] = this->body ->getBytes()[i];
	}
}

void Message::showInfo() {
	cout << endl << "INFO: " << endl;

	// Header
	cout << endl << "\tRAW header: ";
	header->showBytes();
	cout << endl << "\tRAW body: ";
	body->showBytes();
	cout << endl << "\t----------------------" << endl << "\ttype: ";
	showHeaderDataType(header->getDataType(), body);

	// Body
	cout << endl << endl;
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
	if (body->getBytes()[TYPE_FIRST_POSITION] == 0x00 && body->getBytes()[TYPE_SECOND_POSITION]  == 0x00) {
		cout << endl << "\tsubtype: RESET";
	}
	else if (body->getBytes()[TYPE_FIRST_POSITION] == 0x01 && body->getBytes()[TYPE_SECOND_POSITION]  == 0x00) {
		cout << endl << "\tsubtype: GET STATUS";
		if (isCommandReply) {
			showGetStatus(body);
		}
	}
	else if (body->getBytes()[TYPE_FIRST_POSITION] == 0x04 && body->getBytes()[TYPE_SECOND_POSITION]  == 0x00) {
		cout << endl << "\tsubtype: SAVE CONFIG";
	}
	else if (body->getBytes()[TYPE_FIRST_POSITION] == 0x10 && body->getBytes()[TYPE_SECOND_POSITION]  == 0x00) {
		cout << endl << "\tsubtype: SET PARAMETER";
		showParameterType(body, COMMAND_PARAMETER_TYPE_FIRST_POSITION, COMMAND_PARAMETER_TYPE_SECOND_POSITION);
		showParameterValue(body, COMMAND_PARAMETER_VALUE_INIT_POSITION, COMMAND_PARAMETER_VALUE_END_POSITION);
	}
	else if (body->getBytes()[TYPE_FIRST_POSITION] == 0x11 && body->getBytes()[TYPE_SECOND_POSITION]  == 0x00) {
		cout << endl << "\tsubtype: GET PARAMETER";
		if (isCommandReply) {
			showParameterType(body, COMMAND_REPLY_PARAMETER_TYPE_FIRST_POSITION, COMMAND_REPLY_PARAMETER_TYPE_SECOND_POSITION);
			showParameterValue(body, COMMAND_REPLY_PARAMETER_VALUE_INIT_POSITION, COMMAND_REPLY_PARAMETER_VALUE_END_POSITION);
		} else {
			showParameterType(body, COMMAND_PARAMETER_TYPE_FIRST_POSITION, COMMAND_PARAMETER_TYPE_SECOND_POSITION);
		}
	}
	else if (body->getBytes()[TYPE_FIRST_POSITION] == 0x20 && body->getBytes()[TYPE_SECOND_POSITION]  == 0x00) {
		cout << endl << "\tsubtype: START MEASURE";
	}
	else if (body->getBytes()[TYPE_FIRST_POSITION] == 0x21 && body->getBytes()[TYPE_SECOND_POSITION]  == 0x00) {
		cout << endl << "\tsubtype: STOP MEASURE";
	}
	else if (body->getBytes()[TYPE_FIRST_POSITION] == 0x30 && body->getBytes()[TYPE_SECOND_POSITION]  == 0x00) {
		cout << endl << "\tsubtype: SET NTP TIMESTAMP SEC";
	}
	else if (body->getBytes()[TYPE_FIRST_POSITION] == 0x31 && body->getBytes()[TYPE_SECOND_POSITION]  == 0x00) {
		cout << endl << "\tsubtype: SET NTP TIMESTAMP FRAC SEC";
	}
}

void Message::showParameterType(Body* body, int firstPosition, int secondPosition) {
	if (body->getBytes()[firstPosition] == 0x00 && body->getBytes()[secondPosition]  == 0x10) {
		cout << endl << "\tparameter: IP ADDRESS";
	}
	else if (body->getBytes()[firstPosition] == 0x01 && body->getBytes()[secondPosition]  == 0x10) {
		cout << endl << "\tparameter: TCP PORT";
	}
	else if (body->getBytes()[firstPosition] == 0x02 && body->getBytes()[secondPosition]  == 0x10) {
		cout << endl << "\tparameter: SUBNET MASK";
	}
	else if (body->getBytes()[firstPosition] == 0x03 && body->getBytes()[secondPosition]  == 0x10) {
		cout << endl << "\tparameter: STANDARD GATEWAY";
	}
	else if (body->getBytes()[firstPosition] == 0x12 && body->getBytes()[secondPosition]  == 0x10) {
		cout << endl << "\tparameter: DATA OUTPUT FLAG";
	}
	else if (body->getBytes()[firstPosition] == 0x00 && body->getBytes()[secondPosition]  == 0x11) {
		cout << endl << "\tparameter: START ANGLE";
	}
	else if (body->getBytes()[firstPosition] == 0x01 && body->getBytes()[secondPosition]  == 0x11) {
		cout << endl << "\tparameter: END ANGLE";
	}
	else if (body->getBytes()[firstPosition] == 0x02 && body->getBytes()[secondPosition]  == 0x11) {
		cout << endl << "\tparameter: SCAN FRECUENCY";
	}
	else if (body->getBytes()[firstPosition] == 0x03 && body->getBytes()[secondPosition]  == 0x11) {
		cout << endl << "\tparameter: SYNC ANGLE OFFSET";
	}
	else if (body->getBytes()[firstPosition] == 0x04 && body->getBytes()[secondPosition]  == 0x11) {
		cout << endl << "\tparameter: ANGULAR RESOLUTION TYPE";
	}
}

void Message::showParameterValue(Body* body, int initPosition, int endPosition) {
	cout << endl << "\tvalue: ";
	int i;
	for (i = endPosition; i >= initPosition; i--) {
		cout << setw(2) << setfill('0') << hex << uppercase << (int) body->getBytes()[i] << " ";
	}
	cout << dec;
}

void Message::showGetStatus(Body* body) {

	cout << endl << "\tfirmware: ";
	showHex8(body->getBytes()[2]);
	showHex8(body->getBytes()[3]);

	cout << endl << "\tFPGA version: ";
	showHex8(body->getBytes()[4]);
	showHex8(body->getBytes()[5]);

	cout << endl << "\tScanner status: ";
	showHex8(body->getBytes()[6]);
	showHex8(body->getBytes()[7]);

	cout << endl << "\tScanner status: ";
	showHex8(body->getBytes()[6]);
	showHex8(body->getBytes()[7]);
	showHex8(body->getBytes()[8]);
	showHex8(body->getBytes()[9]);

	cout << endl << "\tTemperature: ";
	showHex8(body->getBytes()[12]);
	showHex8(body->getBytes()[13]);

	cout << endl << "\tSerial number 0: ";
	showHex8(body->getBytes()[14]);
	showHex8(body->getBytes()[15]);

	cout << endl << "\tSerial number 1: ";
	showHex8(body->getBytes()[16]);
	showHex8(body->getBytes()[17]);

	cout << endl << "\tFPGA timestamp: ";
	showHex8(body->getBytes()[20]);
	showHex8(body->getBytes()[21]);
	showHex8(body->getBytes()[22]);
	showHex8(body->getBytes()[23]);
	showHex8(body->getBytes()[24]);
	showHex8(body->getBytes()[25]);

	cout << endl << "\tDSP timestamp: ";
	showHex8(body->getBytes()[26]);
	showHex8(body->getBytes()[27]);
	showHex8(body->getBytes()[28]);
	showHex8(body->getBytes()[29]);
	showHex8(body->getBytes()[30]);
	showHex8(body->getBytes()[31]);
}

void Message::showHex8(uint8_t uint8) {
	cout << setw(2) << setfill('0') << hex << uppercase << (int) uint8 << " " << dec;
}

void Message::showScanData(Body* body) {
	int scanPoints = (body->getBytes()[29] * 256) + body->getBytes()[28];
	cout << endl << "\tscan number: " << (body->getBytes()[1] * 256) + body->getBytes()[0];
	cout << endl << "\tscanner status: "; showHex8(body->getBytes()[3]); showHex8(body->getBytes()[2]);
	cout << endl << "\tsync phase offset: " << (body->getBytes()[5] * 256) + body->getBytes()[4];
	cout << endl << "\tscan start time NTP: <TODO>";
	cout << endl << "\tscan end time NTP: <TODO>";
	cout << endl << "\tangle ticks per rotation: " << (body->getBytes()[23] * 256) + body->getBytes()[22];
	cout << endl << "\tstart angle: " << (body->getBytes()[25] * 256) + body->getBytes()[24];
	cout << endl << "\tend angle: " << (body->getBytes()[27] * 256) + body->getBytes()[26];
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
	cout << endl << "\t\tlayer and echo: ";showHex8(body->getBytes()[pointBodyPosition]);
	cout << endl << "\t\tflags: ";showHex8(body->getBytes()[pointBodyPosition + 1]);
	cout << endl << "\t\thorizontal angle: " << (body->getBytes()[pointBodyPosition + 3] * 256) + body->getBytes()[pointBodyPosition + 2];
	cout << endl << "\t\tradial distance: " << (body->getBytes()[pointBodyPosition + 5] * 256) + body->getBytes()[pointBodyPosition + 4];
	cout << endl << "\t\techo pulse width: " << (body->getBytes()[pointBodyPosition + 7] * 256) + body->getBytes()[pointBodyPosition + 6];
}

void Message::showErrorsAndWarnings(Body* body) {

}

