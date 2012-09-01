#include "hdr/GetStatusCommandReplyBody.h"
#include <iomanip>


GetStatusCommandReplyBody::GetStatusCommandReplyBody(int bodySize, uint8_t * bodyBytes):
		Body(bodySize, bodyBytes) {
}

bool GetStatusCommandReplyBody::isGetStatusCommandReplyBody() {
	return true;
}

std::string GetStatusCommandReplyBody::asText() {
	std::stringstream text;
	text << "GET STATUS COMMAND REPLY" << "[";
	text << getAmountBytes() << "]:";

	text << "firmware[";
	text << showHex8(getBytesInRaw()[2]);
	text << showHex8(getBytesInRaw()[3]);
	text << "]:";

	text << "FPGA version: ";
	text << showHex8(getBytesInRaw()[4]);
	text << showHex8(getBytesInRaw()[5]);
	text << "]:";

	text << "Scanner status: ";
	text << showHex8(getBytesInRaw()[6]);
	text << showHex8(getBytesInRaw()[7]);
	text << "]:";

	text << "Scanner status: ";
	text << showHex8(getBytesInRaw()[6]);
	text << showHex8(getBytesInRaw()[7]);
	text << showHex8(getBytesInRaw()[8]);
	text << showHex8(getBytesInRaw()[9]);
	text << "]:";

	text << "Temperature: ";
	text << showHex8(getBytesInRaw()[12]);
	text << showHex8(getBytesInRaw()[13]);
	text << "]:";

	text << "Serial number 0: ";
	text << showHex8(getBytesInRaw()[14]);
	text << showHex8(getBytesInRaw()[15]);
	text << "]:";

	text << "Serial number 1: ";
	text << showHex8(getBytesInRaw()[16]);
	text << showHex8(getBytesInRaw()[17]);
	text << "]:";

	text << "FPGA timestamp: ";
	text << showHex8(getBytesInRaw()[20]);
	text << showHex8(getBytesInRaw()[21]);
	text << showHex8(getBytesInRaw()[22]);
	text << showHex8(getBytesInRaw()[23]);
	text << showHex8(getBytesInRaw()[24]);
	text << showHex8(getBytesInRaw()[25]);
	text << "]:";

	text << "DSP timestamp: ";
	text << showHex8(getBytesInRaw()[26]);
	text << showHex8(getBytesInRaw()[27]);
	text << showHex8(getBytesInRaw()[28]);
	text << showHex8(getBytesInRaw()[29]);
	text << showHex8(getBytesInRaw()[30]);
	text << showHex8(getBytesInRaw()[31]);
	text << "]";

	return text.str();
}

std::string GetStatusCommandReplyBody::showHex8(uint8_t uint8) {
	std::stringstream value;
	value << std::setw(2) << std::setfill('0') << std::hex << std::uppercase << (int) uint8 << " " << std::dec;
	return value.str();
}
