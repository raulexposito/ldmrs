#include "hdr/BodyFactory.h"
#include "../../log/hdr/Logger.h"
#include "../hdr/ResetCommandBody.h"
#include "../hdr/GetStatusCommandReplyBody.h"
#include "../hdr/SaveConfigCommandReplyBody.h"
#include "../hdr/GetParameterCommandReplyBody.h"
#include "../hdr/SetParameterCommandReplyBody.h"
#include "../hdr/StartMeasureCommandReplyBody.h"
#include "../hdr/StopMeasureCommandReplyBody.h"
#include "../hdr/ErrorAndWarningBody.h"
#include "../hdr/ScanDataBody.h"
#include "../../util/hdr/BytesConverter.h"

#define TYPE_FIRST_POSITION 0
#define TYPE_SECOND_POSITION 1

BodyFactory* BodyFactory::instance = 0;

BodyFactory* BodyFactory::getInstance() {
   if (!instance)
	   instance = new BodyFactory;
   return instance;
}

Body* BodyFactory::generateBody (Header * header, uint8_t * bodyBytes) {
	if (header->isCommandReplyHeader()) {
		return generateCommandReplyBody(header->getBodySize(), bodyBytes);
	}
	if (header->isErrorAndWarningHeader()) {
		return new ErrorAndWarningBody(header->getBodySize(), bodyBytes);
	}
	if (header->isScanDataHeader()) {
		return new ScanDataBody(header->getBodySize(), bodyBytes);
	}
	std::stringstream warnMessage;
	warnMessage << "[WARN] UNKNOWN TYPE OF RECEIVED BODY: ";
	warnMessage << BytesConverter::getInstance()->toString(bodyBytes, header->getBodySize());

	Logger::getInstance()->log(warnMessage.str());
	return new Body(header->getBodySize(), bodyBytes);
}

Body* BodyFactory::generateCommandReplyBody(int bodySize, uint8_t * bodyBytes) {
	if (bodyBytes[TYPE_FIRST_POSITION] == 0x11 && bodyBytes[TYPE_SECOND_POSITION]  == 0x00) {
		return new GetParameterCommandReplyBody(bodySize, bodyBytes);
	}
	if (bodyBytes[TYPE_FIRST_POSITION] == 0x01 && bodyBytes[TYPE_SECOND_POSITION]  == 0x00) {
		return new GetStatusCommandReplyBody(bodySize, bodyBytes);
	}
	if (bodyBytes[TYPE_FIRST_POSITION] == 0x10 && bodyBytes[TYPE_SECOND_POSITION]  == 0x00) {
		return new SetParameterCommandReplyBody(bodySize, bodyBytes);
	}
	if (bodyBytes[TYPE_FIRST_POSITION] == 0x04 && bodyBytes[TYPE_SECOND_POSITION]  == 0x00) {
		return new SaveConfigCommandReplyBody(bodySize, bodyBytes);
	}
	if (bodyBytes[TYPE_FIRST_POSITION] == 0x20 && bodyBytes[TYPE_SECOND_POSITION]  == 0x00) {
		return new StartMeasureCommandReplyBody(bodySize, bodyBytes);
	}
	if (bodyBytes[TYPE_FIRST_POSITION] == 0x21 && bodyBytes[TYPE_SECOND_POSITION]  == 0x00) {
		return new StopMeasureCommandReplyBody(bodySize, bodyBytes);
	}

	std::stringstream warnMessage;
	warnMessage << "[WARN] UNKNOWN TYPE OF RECEIVED COMMAND REPLY: ";
	warnMessage << BytesConverter::getInstance()->toString(bodyBytes, bodySize);

	Logger::getInstance()->log(warnMessage.str());
	return new Body(bodySize, bodyBytes);
}
