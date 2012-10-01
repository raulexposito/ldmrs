#include "hdr/BytesConverter.h"

#include <sstream>
#include <iostream>		// para 'cout'
#include <iomanip>		// para formateo de cout
using namespace std;	// para formateo de cout

BytesConverter* BytesConverter::instance = 0;

BytesConverter* BytesConverter::getInstance() {
   if (!instance)
	   instance = new BytesConverter();

   return instance;
}

// http://stackoverflow.com/questions/673240/how-do-i-print-an-unsigned-char-as-hex-in-c-using-ostream
void BytesConverter::print (uint8_t * bytes, int size) {
	int i;
	for (i = 0; i < size; i++) {
		cout << setw(2) << setfill('0') << hex << uppercase << (int) bytes[i] << " ";
	}
	cout << dec;
}

std::string BytesConverter::toString (uint8_t * bytes, int size) {
	std::stringstream result;

	int i;
	for (i = 0; i < size; i++) {
		result << setw(2) << setfill('0') << hex << uppercase << (int) bytes[i] << " ";
	}
	return result.str();
}
