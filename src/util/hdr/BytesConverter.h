#ifndef BYTESCONVERTER_H
#define BYTESCONVERTER_H

#include <stdint.h> 	// para 'uint8_t'
#include <string>

class BytesConverter {

	public:

		static BytesConverter* getInstance();

		void print (uint8_t * bytes, int size);

		std::string toString (uint8_t * bytes, int size);

		uint8_t* toUint8t (char * bytes, int size);

	private:

		BytesConverter(){};
		BytesConverter(BytesConverter const&){};
		static BytesConverter* instance;
};

#endif // BYTESCONVERTER_H
