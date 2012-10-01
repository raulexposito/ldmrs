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
#include "../body/hdr/ScanDataBody.h"
#include "../body/hdr/ErrorAndWarningBody.h"
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
#include "../connector/hdr/Connector.h"

#include <iostream>		// para 'cout'
#include <iomanip>		// para formateo de cout
using namespace std;	// para formateo de cout

void testConector() {
	Connector *connector = new Connector();
	Message *startMeasure = new StartMeasureCommandMessage();
	Message *receivedMessage;

	connector->sendMessage(startMeasure);

	while (true) {
		receivedMessage = connector->receiveMessage();
		receivedMessage->asText();
	}
}

int main () {
	testConector();
	return 0;
}
