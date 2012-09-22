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
	text << "GET STATUS COMMAND REPLY -> ";

	text << "firmware [";
	text << showVersion(getBytesInRaw()[3], getBytesInRaw()[2]);
	text << "], ";

	text << "FPGA version [";
	text << showVersion(getBytesInRaw()[5], getBytesInRaw()[4]);
	text << "], ";

	text << "Scanner status [";
 	text << scannerStatus(getBytesInRaw()[6]);
	text << "], ";

	text << "Temperature [";
	text << temperature(getBytesInRaw()[13], getBytesInRaw()[12]);
	text << "], ";

	text << "Serial number 0 [";
	text << calculateSerialNumber(getBytesInRaw()[15], getBytesInRaw()[14]);
	text << "], ";

	text << "Serial number 1 [";
	text << counterSerialNumber(getBytesInRaw()[17], getBytesInRaw()[16]);
	text << "], ";

	text << "FPGA timestamp [";
	text << calculateTimestamp(getBytesInRaw()[25], getBytesInRaw()[24], getBytesInRaw()[23], getBytesInRaw()[22], getBytesInRaw()[21], getBytesInRaw()[20]);
	text << "], ";

	text << "DSP timestamp [";
	text << calculateTimestamp(getBytesInRaw()[31], getBytesInRaw()[30], getBytesInRaw()[29], getBytesInRaw()[28], getBytesInRaw()[27], getBytesInRaw()[26]);
	text << "]";

	return text.str();
}

std::string GetStatusCommandReplyBody::showHex8(uint8_t uint8) {
	std::stringstream value;
	value << std::setw(2) << std::setfill('0') << std::hex << std::uppercase << (int) uint8 << " " << std::dec;
	return value.str();
}

std::string GetStatusCommandReplyBody::showVersion(uint8_t first, uint8_t second) {
	std::stringstream value;
	value << first / 16 << "." << first % 16 << ".";
	value << second / 16 << "." << second % 16;
	return value.str();
}

// http://www.cplusplus.com/forum/general/10898/
std::string GetStatusCommandReplyBody::scannerStatus(uint8_t n){
    const int size=sizeof(n)*8;
    std::string res;
    std::stringstream message;
    bool s=0;
    for (int a=0;a<size;a++){
        bool bit=n>>(size-1);
        if (bit)
            s=1;
        if (s) {
            res.push_back(bit+'0');
        } else {
        	res.push_back('0');
        }
        n<<=1;
    }

    if (!res.size())
        res.push_back('0');

    if (res.at(0)) {
    	message << "motor on,";
    }
    if (res.at(1)) {
    	message << "laser on,";
    }
    if (res.at(3)) {
    	message << "frecuency locked,";
    }
    if (res.at(4)) {
    	message << "external sync signal available,";
    }
    if (res.at(5)) {
    	message << "phase locked";
    }

    return message.str();
}

float GetStatusCommandReplyBody::temperature(uint8_t first, uint8_t second) {
	float temperature = first * 256 + second;
	temperature -= 579.2364;
	temperature /= 3.63;
	temperature *= -1;
	return temperature;
}

std::string GetStatusCommandReplyBody::calculateSerialNumber(uint8_t first, uint8_t second) {
	std::stringstream value;
	value << "year '" << first / 16 << first % 16 << ",";
	value << "calendar week " << second / 16 << second % 16;
	return value.str();
}

int GetStatusCommandReplyBody::counterSerialNumber(uint8_t first, uint8_t second) {
	return first * 16 + second;
}

std::string GetStatusCommandReplyBody::calculateTimestamp(uint8_t first, uint8_t second, uint8_t third, uint8_t forth, uint8_t fifth, uint8_t sixth) {
	std::stringstream value;
	value << (first * 256 + second) / 16 << " ";
	value << (third * 256 + forth) / 16 << " ";
	value << (fifth * 256 + sixth) / 16;
	return value.str();
}
