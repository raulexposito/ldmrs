#include "../header/hdr/Header.h"
#include "../header/hdr/CommandHeader.h"
#include "../header/hdr/CommandReplyHeader.h"
#include "../header/hdr/ErrorAndWarningHeader.h"
#include "../header/hdr/ScanDataHeader.h"
#include "../body/hdr/GetParameterRequestBody.h"
#include "../message/hdr/ResetMessage.h"
#include "../message/hdr/GetParameterRequestMessage.h"
#include "../message/hdr/SetParameterRequestMessage.h"
#include "../message/hdr/SaveConfigRequestMessage.h"
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

	cout << endl << "comando reset:" << endl;
	resetMessage->showBytes();
	cout << endl << "comando getParameter con IP:" << endl;
	getIPMessage->showBytes();
	cout << endl << "comando getParameter con TCP port:" << endl;
	getPuertoMessage->showBytes();
	cout << endl << "comando save config:" << endl;
	saveConfig->showBytes();
	cout << endl << "comando setParameter:" << endl;
	setParameter->showBytes();

	delete resetMessage;
	delete getIPMessage;
	delete getPuertoMessage;
	delete saveConfig;
	delete setParameter;
}

int main () {
	
//	testShowBytesHeaders();
//	testShowGetParameters();
	testCreateMessages();
	return 0;
}
