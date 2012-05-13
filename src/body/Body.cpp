#include "hdr/Body.h"
#include <iostream>		// para 'cout'
#include <iomanip>		// para formateo de cout
using namespace std;	// para formateo de cout

#define RESERVED 0x00

Body::Body(int bodySize, uint8_t preffix, uint8_t suffix) {
	this->bodySize = bodySize;
	bytes = new uint8_t[bodySize];
	bytes[0] = preffix;
	bytes[1] = suffix;
	bytes[2] = RESERVED;
	bytes[3] = RESERVED;
}

Body::~Body() {
	delete [] bytes;
}

uint8_t * Body::getBytes() {
	return bytes;
}

void Body::showBytes() {
	int i;
	for (i = 0; i < bodySize; i++) {
		cout << setw(2) << setfill('0') << hex << uppercase << (int) bytes[i] << " ";
	}
	cout << dec;
}

