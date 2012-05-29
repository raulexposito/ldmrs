#ifndef HEADER_H
#define HEADER_H

#include <stdint.h> 	// para 'uint8_t'
#include "../enum/HeaderTypeEnum.h"

/**
 * Clase basica con todos los elementos que requieren los encabezados del protocolo LD-MRS
 */
class Header {

	public:

		Header(int dataBlockSize, uint8_t preffix, uint8_t suffix);

		Header(uint8_t * headerBytes);

		virtual ~Header();

		uint8_t * getBytes();

		int getBodySize();

		void showBytes();

		virtual HeaderTypeEnum getDataType()=0;

	protected:

		uint8_t * bytes;

	private:

		void addMagicWord();

		void addSizeOfPreviousMessage();

		void addSizeOfDataBlock(int dataBlockSize);

		void addReservedAndSourceId();

		void addNTPTime();

		void addDataType(uint8_t preffix, uint8_t suffix);
};

#endif // HEADER_H
