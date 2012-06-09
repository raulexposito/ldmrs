#include "../header/hdr/Header.h"
#include "../header/hdr/CommandHeader.h"
#include "../header/hdr/CommandReplyHeader.h"
#include "../header/hdr/ErrorAndWarningHeader.h"
#include "../header/hdr/ScanDataHeader.h"
#include "../header/factory/hdr/HeaderFactory.h"
#include "../body/hdr/GetParameterRequestBody.h"
#include "../message/hdr/ResetMessage.h"
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

	Message *request = new GetParameterRequestMessage(TCP_PORT);
	NetworkClient::getInstance()->send(request);
	Message * response = NetworkClient::getInstance()->receive();

	request->showInfo();
	response->showInfo();

	delete request;
	delete response;
}

int main () {
//	testStartMensajes();
//	testStopMensajes();
//	testLeerLaser();

	testGetParameter();

	return 0;
}

