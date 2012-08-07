#ifndef HEADER_H
#define HEADER_H

#include <stdint.h> 	// para 'uint8_t'
#include "../enum/HeaderTypeEnum.h"

/**
 * Clase basica con todos los elementos que requieren los encabezados del protocolo LD-MRS
 */
class Header {

	public:

		// empleado programaticamente para que los desarrolladores puedan crear encabezados
		// (generalmente de COMMAND)
		Header(int dataBlockSize, uint8_t preffix, uint8_t suffix);

		// empleado por la libreria para almacenar mensajes recibidos
		// (SCAN DATA, ERROR AND WARNING, COMMAND REPLY)
		Header(uint8_t * headerBytes);

		virtual ~Header();

		uint8_t * getBytesInRaw();

		int getBodySize();

		virtual bool isScanDataHeader();

		virtual bool isErrorAndWarningHeader();

		virtual bool isCommandHeader();

		virtual bool isCommandReplyHeader();

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
