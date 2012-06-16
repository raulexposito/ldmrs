#include "../header/hdr/Header.h"
#include "../header/hdr/CommandHeader.h"
#include "../header/hdr/CommandReplyHeader.h"
#include "../header/hdr/ErrorAndWarningHeader.h"
#include "../header/hdr/ScanDataHeader.h"
#include "../header/factory/hdr/HeaderFactory.h"
#include "../body/hdr/GetParameterRequestBody.h"
#include "../body/factory/hdr/BodyFactory.h"
#include "../message/hdr/ResetMessage.h"
#include "../message/hdr/Message.h"
#include "../message/hdr/GetParameterRequestMessage.h"
#include "../message/hdr/GetStatusRequestMessage.h"
#include "../message/hdr/SetParameterRequestMessage.h"
#include "../message/hdr/StopMeasureMessage.h"
#include "../message/hdr/StartMeasureMessage.h"
#include "../message/hdr/SaveConfigMessage.h"
#include "../net/hdr/NetworkClient.h"
#include <iostream>		// para 'cout'
#include <iomanip>		// para formateo de cout
using namespace std;	// para formateo de cout

void testStartMensajes() {

	Message *request = new StartMeasureMessage();
	NetworkClient::getInstance()->send(request);
	Message * response = NetworkClient::getInstance()->receive();

	request->showInfo();
	response->showInfo();

	delete request;
	delete response;
}

void testStopMensajes() {

	Message *request = new StopMeasureMessage();
	NetworkClient::getInstance()->send(request);
	Message * response = NetworkClient::getInstance()->receive();

	request->showInfo();
	response->showInfo();

	delete request;
	delete response;
}

void testLeerLaser() {

	Message * laserRead = NetworkClient::getInstance()->receive();
	laserRead->showInfo();
	delete laserRead;
}

void testGetParameter() {

//	Message *request = new GetParameterRequestMessage(TCP_PORT);
//	NetworkClient::getInstance()->send(request);
//	Message * response = NetworkClient::getInstance()->receive();

//	request->showInfo();
//	response->showInfo();
	uint8_t* headerContent = new uint8_t[24];
	headerContent[0] = 0xAF; // magic word
	headerContent[1] = 0xFE;
	headerContent[2] = 0xC0;
	headerContent[3] = 0xC2;
	headerContent[4] = 0x00; // Size of previous message, here just left to nullL
	headerContent[5] = 0x00;
	headerContent[6] = 0x00;
	headerContent[7] = 0x00;
	headerContent[8] = 0x00; // Size of data block
	headerContent[9] = 0x00;
	headerContent[10] = 0x00;
	headerContent[11] = 0x08;
	headerContent[12] = 0x00;	// Reserved + source Id
	headerContent[13] = 0x00;
	headerContent[14] = 0x20;	// Data Type - 2010 = command
	headerContent[15] = 0x20;
	headerContent[16] = 0x00;	// 4* ntpp time (s) + 4* fractions of a second
	headerContent[17] = 0x05;
	headerContent[18] = 0x26;
	headerContent[19] = 0xBA;
	headerContent[20] = 0x8B;
	headerContent[21] = 0x6E;
	headerContent[22] = 0x27;
	headerContent[23] = 0xFC;

	uint8_t* bodyContent = new uint8_t[8];
	bodyContent[0] = 0x11;	// Command Type - 0020 = start measure
	bodyContent[1] = 0x00;
	bodyContent[2] = 0x00;
	bodyContent[3] = 0x10;
	bodyContent[4] = 0xDD;
	bodyContent[5] = 0x96;
	bodyContent[6] = 0x75;
	bodyContent[7] = 0xA3;

	Header * header = HeaderFactory::getInstance()->generateHeader(headerContent);
	Body * body = BodyFactory::getInstance()->generateBody(header->getBodySize(), bodyContent);
	Message * message = new Message(header, body);

	message->showInfo();

	delete message;
}



int main () {
//	testStartMensajes();
//	testStopMensajes();
//	testLeerLaser();

	testGetParameter();

	return 0;
}

