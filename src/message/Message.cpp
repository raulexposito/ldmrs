#include "hdr/Message.h"
#include "../util/hdr/BytesConverter.h"

#include <iostream>		// para 'cout'
#include <iomanip>		// para formateo de cout
using namespace std;	// para formateo de cout

#define HEADER_SIZE 24

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

std::string Message::asText() {
	std::stringstream text;
	text << this->header->asText();
	text << ":";
	text << this->body->asText();
	text << ":";
	text << BytesConverter::getInstance()->toString(this->getBytesInRaw(), this->getAmountBytes());
	return text.str();
}

