#include <stdint.h> // para 'uint8_t'

/**
 * Clase basica con todos los elementos que requieren los encabezados del protocolo LD-MRS
 */
class Header {
	
	static const int HEADER_SIZE = 24;

	public:

		Header(int dataBlockSize);

		virtual ~Header();

		uint8_t * getBytes();

		void showBytes();

	protected:

		uint8_t * bytes;

		virtual void addDataType()=0;

	private:

		void addMagicWord();

		void addSizeOfPreviousMessage();

		void addSizeOfDataBlock();

		void addReservedAndSourceId();

		void addNTPTime();
};

/**
 * Encabezados de tipo 'scan data'
 */
class ScanDataHeader : public Header {

	public:

	ScanDataHeader(int dataBlockSize): Header(dataBlockSize) {
			addDataType();
		}

	private:

		void addDataType() {
			bytes[14] = 0x22;
			bytes[15] = 0x02;
		}

};

/**
 * Encabezados de tipo 'error and warning'
 */
class ErrorAndWarningHeader : public Header {

	public:

		ErrorAndWarningHeader(int dataBlockSize): Header(dataBlockSize) {
			addDataType();
		}

	private:

		void addDataType() {
			bytes[14] = 0x20;
			bytes[15] = 0x30;
		}

};

/**
 * Encabezados de tipo 'command'
 */
class CommandHeader : public Header {

	public:

		CommandHeader(int dataBlockSize): Header(dataBlockSize) {
			addDataType();
		}

	private:

		void addDataType() {
			bytes[14] = 0x20;
			bytes[15] = 0x10;
		}

};

/**
 * Encabezados de tipo 'command reply'
 */
class CommandReplyHeader : public Header {

	public:

		CommandReplyHeader(int dataBlockSize): Header(dataBlockSize) {
			addDataType();
		}

	private:

		void addDataType() {
			bytes[14] = 0x20;
			bytes[15] = 0x20;
		}

};

