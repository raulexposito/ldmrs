#ifndef HEADER_H
#define HEADER_H

#include <stdint.h> 	// para 'uint8_t'

/**
 * Clase basica con todos los elementos que requieren los encabezados del protocolo LD-MRS
 */
class Header {

	public:

		Header(int dataBlockSize, uint8_t preffix, uint8_t suffix);

		virtual ~Header();

		uint8_t * getBytes();

		void showBytes();

	protected:

		uint8_t * bytes;

	private:

		void addMagicWord();

		void addSizeOfPreviousMessage();

		void addSizeOfDataBlock();

		void addReservedAndSourceId();

		void addNTPTime();

		void addDataType(uint8_t preffix, uint8_t suffix);
};

#endif // HEADER_H
