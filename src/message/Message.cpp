#include "hdr/Message.h"

#define HEADER_SIZE 24

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

void Message::showBytes() {
	this->header->showBytes();
	this->body->showBytes();
}

uint8_t* Message::getBytes() {
	return bytes;
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
