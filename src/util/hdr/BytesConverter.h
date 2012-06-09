#ifndef BYTESCONVERTER_H
#define BYTESCONVERTER_H

#include <stdint.h> 	// para 'uint8_t'

class BytesConverter {

	public:

		static BytesConverter* getInstance();

		void print (uint8_t * bytes, int size);

	private:

		BytesConverter(){};
		BytesConverter(BytesConverter const&){};
		static BytesConverter* instance;
};

#endif // BYTESCONVERTER_H
