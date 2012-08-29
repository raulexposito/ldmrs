#include "../header/hdr/Header.h"
#include "../header/hdr/CommandHeader.h"
#include "../header/hdr/CommandReplyHeader.h"
#include "../header/hdr/ErrorAndWarningHeader.h"
#include "../header/hdr/ScanDataHeader.h"
#include "../header/factory/hdr/HeaderFactory.h"
#include "../body/hdr/GetParameterCommandBody.h"
#include "../body/hdr/ResetCommandBody.h"
#include "../body/hdr/StartMeasureCommandBody.h"
#include "../body/hdr/StopMeasureCommandBody.h"
#include "../body/factory/hdr/BodyFactory.h"
#include "../body/enum/ParameterEnum.h"
#include "../message/hdr/ResetCommandMessage.h"
#include "../message/hdr/GetParameterCommandMessage.h"
#include "../message/hdr/GetStatusCommandMessage.h"
#include "../message/hdr/SetParameterCommandMessage.h"
#include "../message/hdr/StopMeasureCommandMessage.h"
#include "../message/hdr/StartMeasureCommandMessage.h"
#include "../message/hdr/SaveConfigCommandMessage.h"
#include "../net/hdr/NetworkClient.h"
#include "../config/hdr/Configuration.h"
#include "../log/hdr/Logger.h"
#include "../log/hdr/Recorder.h"
#include "../util/hdr/DateTime.h"
#include "../util/hdr/BytesConverter.h"
#include "../file/hdr/FileClient.h"

#include <time.h>
#include <iostream>		// para 'cout'
#include <iomanip>		// para formateo de cout
using namespace std;	// para formateo de cout

void testStartMensajes() {
	Message *request = new StartMeasureCommandMessage();
	NetworkClient::getInstance()->send(request);
	Message * response = NetworkClient::getInstance()->receive();

	delete request;
	delete response;
}

void testStopMensajes() {
	Message *request = new StopMeasureCommandMessage();
	NetworkClient::getInstance()->send(request);
	Message * response = NetworkClient::getInstance()->receive();
	delete request;
	delete response;
}

void testReset() {
	Message *request = new ResetCommandMessage();
	NetworkClient::getInstance()->send(request);
	delete request;
}

void testLeerLaser() {

//	Message *request = new StartMeasureMessage();
//	NetworkClient::getInstance()->send(request);

	Message * laserRead = NetworkClient::getInstance()->receive();
	delete laserRead;
}

void testGetParameter() {

	Message *request = new GetParameterCommandMessage(TCP_PORT);
	NetworkClient::getInstance()->send(request);
	Message * response = NetworkClient::getInstance()->receive();

	delete request;
	delete response;
}


Header* generateHeader (int numerico) {

	if (numerico == 0) {
		return new CommandHeader(10);
	} else if (numerico == 1) {
		return new CommandReplyHeader(new uint8_t[3]);
	} else if (numerico == 2) {
		return new ErrorAndWarningHeader(new uint8_t[3]);
	}
	return new ScanDataHeader(new uint8_t[3]);
}

void testTiposEncabezado() {
	Header *command = generateHeader(0);
	cout << command->isCommandHeader() << endl;
	cout << command->isCommandReplyHeader() << endl;
	cout << command->isErrorAndWarningHeader() << endl;
	cout << command->isScanDataHeader() << endl << endl;
	delete command;

	Header *commandReply = generateHeader(1);
	cout << commandReply->isCommandHeader() << endl;
	cout << commandReply->isCommandReplyHeader() << endl;
	cout << commandReply->isErrorAndWarningHeader() << endl;
	cout << commandReply->isScanDataHeader() << endl << endl;
	delete commandReply;

	Header *errorAndWarningHeader = generateHeader(2);
	cout << errorAndWarningHeader->isCommandHeader() << endl;
	cout << errorAndWarningHeader->isCommandReplyHeader() << endl;
	cout << errorAndWarningHeader->isErrorAndWarningHeader() << endl;
	cout << errorAndWarningHeader->isScanDataHeader() << endl << endl;
	delete errorAndWarningHeader;

	Header *scanDataHeader = generateHeader(3);
	cout << scanDataHeader->isCommandHeader() << endl;
	cout << scanDataHeader->isCommandReplyHeader() << endl;
	cout << scanDataHeader->isErrorAndWarningHeader() << endl;
	cout << scanDataHeader->isScanDataHeader() << endl << endl;
	delete command;
}

Body* generateBody (int numerico) {

	if (numerico == 0) {
		return new StartMeasureCommandBody();
	} else if (numerico == 1) {
		return new StopMeasureCommandBody();
	} else if (numerico == 2) {
		return new ResetCommandBody();
	}
	return new GetParameterCommandBody(IP_ADDRESS);
}

void testTiposCuerpo() {
	Body *startMeasure = generateBody(0);
	cout << startMeasure->isStartMeasureCommandBody() << endl;
	cout << startMeasure->isStopMeasureCommandBody() << endl;
	cout << startMeasure->isResetCommandBody() << endl;
	cout << startMeasure->isGetParameterCommandBody() << endl << endl;
	delete startMeasure;

	Body *stopMeasure = generateBody(1);
	cout << stopMeasure->isStartMeasureCommandBody() << endl;
	cout << stopMeasure->isStopMeasureCommandBody() << endl;
	cout << stopMeasure->isResetCommandBody() << endl;
	cout << stopMeasure->isGetParameterCommandBody() << endl << endl;
	delete stopMeasure;

	Body *reset = generateBody(2);
	cout << reset->isStartMeasureCommandBody() << endl;
	cout << reset->isStopMeasureCommandBody() << endl;
	cout << reset->isResetCommandBody() << endl;
	cout << reset->isGetParameterCommandBody() << endl << endl;
	delete reset;

	Body *getParameter = generateBody(3);
	cout << getParameter->isStartMeasureCommandBody() << endl;
	cout << getParameter->isStopMeasureCommandBody() << endl;
	cout << getParameter->isResetCommandBody() << endl;
	cout << getParameter->isGetParameterCommandBody() << endl << endl;
	delete getParameter;
}

void testGenerarLog() {
	Logger::getInstance()->log("prueba logger");
}

void testProperties () {
	cout << Configuration::getInstance()->getSource() << endl;
	cout << Configuration::getInstance()->getIp() << endl;
	cout << Configuration::getInstance()->getPort() << endl;
	cout << Configuration::getInstance()->getPath() << endl;
}

void testDateTime () {
	cout << DateTime::getInstance()->getCurrentDate("-") << " ";
	cout << DateTime::getInstance()->getCurrentTime(":") << endl;
}

void testRecordTrace () {

//	RAW header: AF FE C0 C2 00 00 00 00 00 00 00 02 00 00 20 20 00 05 47 2F D6 90 06 38
//	RAW body: 21 00

	uint8_t* headerBytes = new uint8_t[24];
	headerBytes[0] = 0xAF; // magic word
	headerBytes[1] = 0xFE;
	headerBytes[2] = 0xC0;
	headerBytes[3] = 0xC2;
	headerBytes[4] = 0x00; // Size of previous message, here just left to nullL
	headerBytes[5] = 0x00;
	headerBytes[6] = 0x00;
	headerBytes[7] = 0x00;
	headerBytes[8] = 0x00; // Size of data block
	headerBytes[9] = 0x00;
	headerBytes[10] = 0x00;
	headerBytes[11] = 0x02;
	headerBytes[12] = 0x00;	// Reserved + source Id
	headerBytes[13] = 0x00;
	headerBytes[14] = 0x20;	// Data Type - 2010 = command
	headerBytes[15] = 0x20;
	headerBytes[16] = 0x00;	// 4* ntpp time (s) + 4* fractions of a second
	headerBytes[17] = 0x05;
	headerBytes[18] = 0x47;
	headerBytes[19] = 0x2F;
	headerBytes[20] = 0xD6;
	headerBytes[21] = 0x90;
	headerBytes[22] = 0x06;
	headerBytes[23] = 0x38;

	uint8_t* bodyBytes = new uint8_t[2];
	bodyBytes[24] = 0x21;
	bodyBytes[25] = 0x00;

	Header *header = new Header(headerBytes);
	Body *body = new Body(header->getBodySize(), bodyBytes);

	Message *message = new Message (header, body);

	int i = 0;
	for (i = 0; i < 10; i++) {
		Recorder::getInstance()->record(message);
	}

}

void testLecturaLaser() {
	testStopMensajes();
	testReset();
	testStartMensajes();

	while (true) {
		NetworkClient::getInstance()->receive();
	}
}

void testReadRecord() {
	//for (int i = 0; i < 100; i++) {
		FileClient::getInstance()->receive();
	//}
}

void testAsText() {
	Header *command = generateHeader(0);
	cout << command->asText() << endl;
	delete command;

	Header *commandReply = generateHeader(1);
	cout << commandReply->asText() << endl;
	delete commandReply;

	Header *errorAndWarningHeader = generateHeader(2);
	cout << errorAndWarningHeader->asText() << endl;
	delete errorAndWarningHeader;

	Header *scanDataHeader = generateHeader(3);
	cout << scanDataHeader->asText() << endl;
	delete command;

	Body *getParameter = generateBody(0);
	cout << getParameter->asText() << endl;
	delete getParameter;
}

int main () {
//	testStartMensajes();
//	testStopMensajes();
//	testLeerLaser();

//	testGetParameter();

//	testTiposEncabezado();

//	testTiposCuerpo();

//	testGenerarLog();

//	testDateTime();

//	testRecordTrace();

//	testLecturaLaser();

//	testReadRecord();

	testAsText();

	return 0;
}
