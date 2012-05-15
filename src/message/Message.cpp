#include "hdr/Message.h"

Message::~Message() {
	delete header;
	delete body;
}

void Message::showBytes() {
	this->header->showBytes();
	this->body->showBytes();
}

