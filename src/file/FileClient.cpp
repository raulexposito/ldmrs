#include "hdr/FileClient.h"
#include "../config/hdr/Configuration.h"
#include "../header/hdr/Header.h"
#include "../body/hdr/Body.h"
#include "../header/factory/hdr/HeaderFactory.h"
#include "../body/factory/hdr/BodyFactory.h"

#define HEADER_SIZE 24
#define CHARS_PER_BYTE 2
#define RETURN 2

FileClient* FileClient::instance = 0;

FileClient* FileClient::getInstance() {
   if (!instance)
	   instance = new FileClient();

   return instance;
}

FileClient::FileClient () {
	ifs.open(Configuration::getInstance()->getPath(), ifstream::in);
}

Message * FileClient::receive () {

	char * headerReadedBytes = new char[HEADER_SIZE * CHARS_PER_BYTE + RETURN + 1];
	ifs.get(headerReadedBytes, HEADER_SIZE * CHARS_PER_BYTE + RETURN  + 1);

	Header * header = generateHeader (headerReadedBytes);

	char * bodyReadedBytes = new char[header->getBodySize() * CHARS_PER_BYTE + RETURN  + 1];
	ifs.get(bodyReadedBytes, header->getBodySize() * CHARS_PER_BYTE + RETURN  + 1);

	Body * body = generateBody (bodyReadedBytes, header);

	if (ifs.eof()) {
		ifs.clear();
		ifs.seekg(0);
	}

	free(headerReadedBytes);
	free(bodyReadedBytes);

	sleep (Configuration::getInstance()->getMilisecondsBetweenMessages());

	return new Message(header, body);
}

Header * FileClient::generateHeader (char * headerReadedBytes) {
	uint8_t * headerBytes = new uint8_t[HEADER_SIZE * CHARS_PER_BYTE + RETURN  + 1];
	int i = 0;
	for (i = 0; i < HEADER_SIZE; i++) {
		headerBytes[i] = convert(headerReadedBytes[(i * 2)], true);
		headerBytes[i] += convert(headerReadedBytes[(i * 2) + 1], false);
	}

	return HeaderFactory::getInstance()->generateHeader(headerBytes);
}

Body * FileClient::generateBody (char * bodyReadedBytes, Header * header) {
	uint8_t * bodyBytes = new uint8_t[header->getBodySize() * CHARS_PER_BYTE + RETURN  + 1];
	int i = 0;
	for (i = 0; i < header->getBodySize(); i++) {
		bodyBytes[i] = convert(bodyReadedBytes[(i * 2)], true);
		bodyBytes[i] += convert(bodyReadedBytes[(i * 2) + 1], false);
	}

	return BodyFactory::getInstance()->generateBody(header, bodyBytes);
}

uint8_t FileClient::convert(char value, bool first) {

	uint8_t returnValue;

	if (value == 'a' || value == 'A') {
		returnValue = (uint8_t) 10;
	}
	else if (value == 'b' || value == 'B' ) {
		returnValue = (uint8_t) 11;
	}
	else if (value == 'c' || value == 'C' ) {
		returnValue = (uint8_t) 12;
	}
	else if (value == 'd' || value == 'D' ) {
		returnValue = (uint8_t) 13;
	}
	else if (value == 'e' || value == 'E' ) {
		returnValue = (uint8_t) 14;
	}
	else if (value == 'f' || value == 'F' ) {
		returnValue = (uint8_t) 15;
	}
	else {
		returnValue = (uint8_t) value - '0';
	}

	if (first) {
		returnValue *= 16;
	}

	return returnValue;
}
