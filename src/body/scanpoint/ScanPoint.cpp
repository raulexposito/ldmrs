#include "hdr/ScanPoint.h"

ScanPoint::ScanPoint(uint8_t data0, uint8_t data1, uint8_t data2, uint8_t data3, uint8_t data4, uint8_t data5, uint8_t data6, uint8_t data7) {
	byte0 = data0;
	byte1 = data1;
	byte2 = data2;
	byte3 = data3;
	byte4 = data4;
	byte5 = data5;
	byte6 = data6;
	byte7 = data7;
}

int ScanPoint::getLayer() {
	return byte0 % 16;
}

int ScanPoint::getEcho() {
	return byte0 / 16;
}

std::string ScanPoint::getFlags() {
	if (byte1 == 80) return "transparent";
	if (byte1 == 40) return "clutter    ";
	if (byte1 == 1)  return "dirt       ";
	return "reserved";
}

int ScanPoint::getHorizontalAngle() {
	return byte3 * 256 + byte2;
}

int ScanPoint::getRadialDistance() {
	return byte5 * 256 + byte4;
}

int ScanPoint::getEchoPulseWidth() {
	return byte7 * 256 + byte6;
}

uint8_t* ScanPoint::getBytesInRaw() {
	uint8_t* bytes = new uint8_t[8];
	bytes[0] = byte0;
	bytes[1] = byte1;
	bytes[2] = byte2;
	bytes[3] = byte3;
	bytes[4] = byte4;
	bytes[5] = byte5;
	bytes[6] = byte6;
	bytes[7] = byte7;
	return bytes;
}
