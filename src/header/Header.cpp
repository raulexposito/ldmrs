#include "hdr/Header.h"
#include "../util/hdr/BytesConverter.h"

#define HEADER_SIZE 24
#define LENGTH_FIRST_POSITION 8

Header::Header (int dataBlockSize, uint8_t preffix, uint8_t suffix) {
	bytes = new uint8_t[HEADER_SIZE];
	addMagicWord();
	addSizeOfPreviousMessage();
	addSizeOfDataBlock(dataBlockSize);
	addReservedAndSourceId();
	addDataType(preffix, suffix);
	addNTPTime();
}

Header::Header (uint8_t * headerBytes) {
	bytes = new uint8_t[HEADER_SIZE];
	bytes = headerBytes;
}

void Header::addMagicWord() {
	bytes[0] = 0xAF;
	bytes[1] = 0xFE;
	bytes[2] = 0xC0;
	bytes[3] = 0xC2;
}

void Header::addSizeOfPreviousMessage() {
	bytes[4] = 0x00;
	bytes[5] = 0x00;
	bytes[6] = 0x00;
	bytes[7] = 0x00;
}

void Header::addSizeOfDataBlock(int dataBlockSize) {
	uint32_t dataBlock32 = dataBlockSize;
	bytes[8] = (dataBlock32 & 0xff000000) >> 24;
	bytes[9] = (dataBlock32 & 0x00ff0000) >> 16;
	bytes[10] = (dataBlock32 & 0x0000ff00) >> 8;
	bytes[11] = (dataBlock32 & 0x000000ff);
}

void Header::addReservedAndSourceId() {
	bytes[12] = 0x00;
	bytes[13] = 0x00;
}

void Header::addDataType(uint8_t preffix, uint8_t suffix) {
	bytes[14] = preffix;
	bytes[15] = suffix;
}

// TODO: implementar
void Header::addNTPTime() {
	bytes[16] = 0x00;
	bytes[17] = 0x00;
	bytes[18] = 0x00;
	bytes[19] = 0x00;
	bytes[20] = 0x00;
	bytes[21] = 0x00;
	bytes[22] = 0x00;
	bytes[23] = 0x00;
}

Header::~Header() {
	delete [] bytes;
}

uint8_t * Header::getBytesInRaw() {
	return bytes;
}

int Header::getBodySize () {
	int bodySize;
	bodySize = static_cast<int>(bytes[LENGTH_FIRST_POSITION]) * 16777216;
	bodySize += static_cast<int>(bytes[LENGTH_FIRST_POSITION + 1]) * 65536;
	bodySize += static_cast<int>(bytes[LENGTH_FIRST_POSITION + 2]) * 256;
	bodySize += static_cast<int>(bytes[LENGTH_FIRST_POSITION + 3]);
	return bodySize;
}

bool Header::isScanDataHeader() { return false; }

bool Header::isErrorAndWarningHeader() { return false; }

bool Header::isCommandHeader() { return false; }

bool Header::isCommandReplyHeader() { return false; }

std::string Header::asText() {
	std::stringstream text;
	text << "GENERIC HEADER";
	return text.str();
}
