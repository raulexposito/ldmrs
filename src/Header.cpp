#include "Header.h"
#include <iostream>		// para 'cout'
#include <iomanip>		// para formateo de cout
using namespace std;	// para formateo de cout

Header::Header (int dataBlockSize, uint8_t preffix, uint8_t suffix) {

	bytes = new uint8_t[HEADER_SIZE];
	addMagicWord();
	addSizeOfPreviousMessage();
	addSizeOfDataBlock();
	addReservedAndSourceId();
	addDataType(preffix, suffix);
	addNTPTime();
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

// TODO: convertir a hexadecimal
void Header::addSizeOfDataBlock() {
	bytes[8] = 0x00;
	bytes[9] = 0x00;
	bytes[10] = 0x00;
	bytes[11] = 0x0A;
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

uint8_t * Header::getBytes() {
	return bytes;
}

// http://stackoverflow.com/questions/673240/how-do-i-print-an-unsigned-char-as-hex-in-c-using-ostream
void Header::showBytes() {
	int i;
	for (i = 0; i < HEADER_SIZE; i++) {
		cout << setw(2) << setfill('0') << hex << uppercase << (int) bytes[i] << " ";
	}
	cout << dec;
}
