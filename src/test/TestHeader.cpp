#include "../header/hdr/Header.h"
#include "../header/hdr/CommandHeader.h"
#include "../header/hdr/CommandReplyHeader.h"
#include "../header/hdr/ErrorAndWarningHeader.h"
#include "../header/hdr/ScanDataHeader.h"
#include "../header/factory/hdr/HeaderFactory.h"
#include "../body/hdr/GetParameterRequestBody.h"
#include "../message/hdr/ResetMessage.h"
#include "../message/hdr/GetParameterRequestMessage.h"
#include "../message/hdr/SetParameterRequestMessage.h"
#include "../message/hdr/SaveConfigRequestMessage.h"
#include "../net/hdr/NetworkClient.h"
#include <iostream>		// para 'cout'
#include <iomanip>		// para formateo de cout
using namespace std;	// para formateo de cout

void testShowBytesHeaders() {
	Header *scanDataHeader = new ScanDataHeader(42);
	Header *errorAndWarningHeader = new ErrorAndWarningHeader(42);
	Header *commandHeader = new CommandHeader(42);
	Header *commandReplyHeader = new CommandReplyHeader(42);

	scanDataHeader->showBytes();
	cout << endl;
	errorAndWarningHeader->showBytes();
	cout << endl;
	commandHeader->showBytes();
	cout << endl;
	commandReplyHeader->showBytes();

	delete scanDataHeader;
	delete errorAndWarningHeader;
	delete commandHeader;
	delete commandReplyHeader;
}

void testShowGetParameters() {
	Body *getParameterIP = new GetParameterRequestBody(IP_ADDRESS);
	Body *getParameterGateway = new GetParameterRequestBody(STANDARD_GATEWAY);

	getParameterIP->showBytes();
	cout << endl;
	getParameterGateway->showBytes();

	delete getParameterIP;
	delete getParameterGateway;
}

void testCreateMessages() {
	Message *resetMessage = new ResetMessage();
	Message *getIPMessage = new GetParameterRequestMessage(IP_ADDRESS);
	Message *getPuertoMessage = new GetParameterRequestMessage(TCP_PORT);
	Message *saveConfig = new SaveConfigRequestMessage();
	Message *setParameter = new SetParameterRequestMessage(START_ANGLE, 0x12345678);

	cout << endl << "comando reset [" << resetMessage->getAmountBytes() << " bytes]: " << endl;
	resetMessage->showBytes();
	cout << endl << "comando getParameter con IP [" << getIPMessage->getAmountBytes() << " bytes]: " << endl;
	getIPMessage->showBytes();
	cout << endl << "comando getParameter con TCP port [" << getPuertoMessage->getAmountBytes() << " bytes]: " << endl;
	getPuertoMessage->showBytes();
	cout << endl << "comando save config [" << saveConfig->getAmountBytes() << " bytes]: " << endl;
	saveConfig->showBytes();
	cout << endl << "comando setParameter [" << setParameter->getAmountBytes() << " bytes]: " << endl;
	setParameter->showBytes();

	delete resetMessage;
	delete getIPMessage;
	delete getPuertoMessage;
	delete saveConfig;
	delete setParameter;
}

void testMandarMensajes() {
	Message *getIPMessage = new GetParameterRequestMessage(IP_ADDRESS);
	NetworkClient::getInstance()->send(getIPMessage);
	delete getIPMessage;
}

void testHeaderFactory() {
	uint8_t * headerBytes = new uint8_t[26];
	headerBytes[0] = 0xAF;
	headerBytes[1] = 0xFE;
	headerBytes[2] = 0xC0;
	headerBytes[3] = 0xC2;
	headerBytes[4] = 0x00;
	headerBytes[5] = 0x00;
	headerBytes[6] = 0x00;
	headerBytes[7] = 0x00;
	headerBytes[8] = 0x00;
	headerBytes[9] = 0x00;
	headerBytes[10] = 0x00;
	headerBytes[11] = 0x19;
	headerBytes[12] = 0x00;
	headerBytes[13] = 0x00;
	headerBytes[14] = 0x20;	// Data Type - 2030 = error and warnings
	headerBytes[15] = 0x30;
	headerBytes[16] = 0x00;
	headerBytes[17] = 0x00;
	headerBytes[18] = 0x00;
	headerBytes[19] = 0x00;
	headerBytes[20] = 0x00;
	headerBytes[21] = 0x00;
	headerBytes[22] = 0x00;
	headerBytes[23] = 0x00;

	Header * header = HeaderFactory::getInstance()->generateHeader(headerBytes);

	switch (header->getType()) {
		case SCAN_DATA:
			cout << "SCAN_DATA";
			break;
		case ERRORS_AND_WARNINGS:
			cout << "ERRORS_AND_WARNINGS";
			break;
		case COMMAND:
			cout << "COMMAND";
			break;
		case COMMAND_REPLY:
			cout << "COMMAND_REPLY";
			break;
	}

	delete headerBytes;
}

int main () {
	
//	testShowBytesHeaders();
//	testShowGetParameters();
//	testCreateMessages();
//	testMandarMensajes();
	testHeaderFactory();
	return 0;
}

