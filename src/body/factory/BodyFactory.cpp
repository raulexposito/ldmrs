#include "hdr/BodyFactory.h"
#include "../hdr/ResetBody.h"
#include "../hdr/GetStatusReplyBody.h"
#include "../hdr/SaveConfigBody.h"
#include "../hdr/SetParameterReplyBody.h"
#include "../hdr/GetParameterReplyBody.h"
#include "../hdr/StartMeasureBody.h"
#include "../hdr/StopMeasureBody.h"
#include "../hdr/SetNTPTimestampSecReplyBody.h"
#include "../hdr/SetNTPTimestampFracSecReplyBody.h"

#define TYPE_FIRST_POSITION 0
#define TYPE_SECOND_POSITION 1

#define PARAMETER_FIRST_POSITION 4
#define PARAMETER_SECOND_POSITION 5

BodyFactory* BodyFactory::instance = 0;

BodyFactory* BodyFactory::getInstance() {
   if (!instance)
	   instance = new BodyFactory;

   return instance;
}

Body* BodyFactory::generateBody (HeaderTypeEnum headerType, uint8_t * bodyBytes) {

	Body * body;

	switch (headerType) {
		case SCAN_DATA:
			// TODO
			break;
		case ERRORS_AND_WARNINGS:
			// TODO
			break;
		case COMMAND_REPLY:
			// TODO: tiempo de los NTP y valor en el setParameter
			if (isReset(bodyBytes)) body = new ResetBody();
			else if (isGetStatus(bodyBytes)) body = new GetStatusReplyBody();
			else if (isSaveConfig(bodyBytes)) body = new SaveConfigBody();
			else if (isSetParameter(bodyBytes)) body = new SetParameterReplyBody(getParameter(bodyBytes));
			else if (isGetParameter(bodyBytes)) body = new GetParameterReplyBody(getParameter(bodyBytes));
			else if (isStartMeasure(bodyBytes)) body = new StartMeasureBody();
			else if (isStopMeasure(bodyBytes)) body = new StopMeasureBody();
			else if (isSetNTPTimestampSec(bodyBytes)) body = new SetNTPTimestampSecReplyBody(0);
			else if (isSetNTPTimestampFracSec(bodyBytes)) body = new SetNTPTimestampFracSecReplyBody(0);
			break;
		case COMMAND: break;
	}
	return body;
}

bool BodyFactory::isReset(uint8_t * bodyBytes) {
	return (bodyBytes[TYPE_FIRST_POSITION] == 0x00 && bodyBytes[TYPE_SECOND_POSITION] == 0x00);
}

bool BodyFactory::isGetStatus(uint8_t * bodyBytes) {
	return (bodyBytes[TYPE_FIRST_POSITION] == 0x01 && bodyBytes[TYPE_SECOND_POSITION] == 0x00);
}

bool BodyFactory::isSaveConfig(uint8_t * bodyBytes) {
	return (bodyBytes[TYPE_FIRST_POSITION] == 0x04 && bodyBytes[TYPE_SECOND_POSITION] == 0x00);
}

bool BodyFactory::isSetParameter(uint8_t * bodyBytes) {
	return (bodyBytes[TYPE_FIRST_POSITION] == 0x10 && bodyBytes[TYPE_SECOND_POSITION] == 0x00);
}

bool BodyFactory::isGetParameter(uint8_t * bodyBytes) {
	return (bodyBytes[TYPE_FIRST_POSITION] == 0x11 && bodyBytes[TYPE_SECOND_POSITION] == 0x00);
}

bool BodyFactory::isStartMeasure(uint8_t * bodyBytes) {
	return (bodyBytes[TYPE_FIRST_POSITION] == 0x20 && bodyBytes[TYPE_SECOND_POSITION] == 0x00);
}

bool BodyFactory::isStopMeasure(uint8_t * bodyBytes) {
	return (bodyBytes[TYPE_FIRST_POSITION] == 0x21 && bodyBytes[TYPE_SECOND_POSITION] == 0x00);
}

bool BodyFactory::isSetNTPTimestampSec(uint8_t * bodyBytes) {
	return (bodyBytes[TYPE_FIRST_POSITION] == 0x30 && bodyBytes[TYPE_SECOND_POSITION] == 0x00);
}

bool BodyFactory::isSetNTPTimestampFracSec(uint8_t * bodyBytes) {
	return (bodyBytes[TYPE_FIRST_POSITION] == 0x31 && bodyBytes[TYPE_SECOND_POSITION] == 0x00);
}

ParameterEnum BodyFactory::getParameter(uint8_t * bodyBytes) {
	if (isIpAddress(bodyBytes)) return IP_ADDRESS;
	else if (isTcpPort(bodyBytes)) return TCP_PORT;
	else if (isSubnetMask(bodyBytes)) return SUBNET_MASK;
	else if (isStandardGateway(bodyBytes)) return STANDARD_GATEWAY;
	else if (isDataOutputFlag(bodyBytes)) return DATA_OUTPUT_FLAG;
	else if (isStartAngle(bodyBytes)) return START_ANGLE;
	else if (isEndAngle(bodyBytes)) return END_ANGLE;
	else if (isScanFrecuency(bodyBytes)) return SCAN_FRECUENCY;
	else if (isSyncAngleOffset(bodyBytes)) return SYNC_ANGLE_OFFSET;
	else if (isAngularResolutionType(bodyBytes)) return ANGULAR_RESOLUTION_TYPE;
	return ANGLE_TICKS_PER_ROTATION;
}

bool BodyFactory::isIpAddress(uint8_t * bodyBytes) {
	return (bodyBytes[PARAMETER_FIRST_POSITION] == 0x00 && bodyBytes[PARAMETER_SECOND_POSITION] == 0x10);
}
bool BodyFactory::isTcpPort(uint8_t * bodyBytes) {
	return (bodyBytes[PARAMETER_FIRST_POSITION] == 0x01 && bodyBytes[PARAMETER_SECOND_POSITION] == 0x10);
}
bool BodyFactory::isSubnetMask(uint8_t * bodyBytes) {
	return (bodyBytes[PARAMETER_FIRST_POSITION] == 0x02 && bodyBytes[PARAMETER_SECOND_POSITION] == 0x10);
}
bool BodyFactory::isStandardGateway(uint8_t * bodyBytes) {
	return (bodyBytes[PARAMETER_FIRST_POSITION] == 0x03 && bodyBytes[PARAMETER_SECOND_POSITION] == 0x10);
}
bool BodyFactory::isDataOutputFlag(uint8_t * bodyBytes) {
	return (bodyBytes[PARAMETER_FIRST_POSITION] == 0x12 && bodyBytes[PARAMETER_SECOND_POSITION] == 0x10);
}
bool BodyFactory::isStartAngle(uint8_t * bodyBytes) {
	return (bodyBytes[PARAMETER_FIRST_POSITION] == 0x00 && bodyBytes[PARAMETER_SECOND_POSITION] == 0x11);
}
bool BodyFactory::isEndAngle(uint8_t * bodyBytes) {
	return (bodyBytes[PARAMETER_FIRST_POSITION] == 0x01 && bodyBytes[PARAMETER_SECOND_POSITION] == 0x11);
}
bool BodyFactory::isScanFrecuency(uint8_t * bodyBytes) {
	return (bodyBytes[PARAMETER_FIRST_POSITION] == 0x02 && bodyBytes[PARAMETER_SECOND_POSITION] == 0x11);
}
bool BodyFactory::isSyncAngleOffset(uint8_t * bodyBytes) {
	return (bodyBytes[PARAMETER_FIRST_POSITION] == 0x03 && bodyBytes[PARAMETER_SECOND_POSITION] == 0x11);
}
bool BodyFactory::isAngularResolutionType(uint8_t * bodyBytes) {
	return (bodyBytes[PARAMETER_FIRST_POSITION] == 0x04 && bodyBytes[PARAMETER_SECOND_POSITION] == 0x11);
}



