#include <stdint.h> 	// para 'uint8_t'

/**
 * Clase basica con todos los elementos que requieren los encabezados del protocolo LD-MRS
 */
class Header {
	
	static const int HEADER_SIZE = 24;

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

/**
 * Encabezados de tipo 'scan data'
 */
class ScanDataHeader : public Header {

	static const uint8_t SCAN_DATA_HEADER_PREFFIX = 0x22;
	static const uint8_t SCAN_DATA_HEADER_SUFFIX = 0x02;

	public:
		ScanDataHeader(int dataBlockSize):
			Header(dataBlockSize, SCAN_DATA_HEADER_PREFFIX, SCAN_DATA_HEADER_SUFFIX) {}
};

/**
 * Encabezados de tipo 'error and warning'
 */
class ErrorAndWarningHeader : public Header {

	static const uint8_t ERROR_WARNING_HEADER_PREFFIX = 0x20;
	static const uint8_t ERROR_WARNING_HEADER_SUFFIX = 0x30;

	public:
		ErrorAndWarningHeader(int dataBlockSize):
			Header(dataBlockSize, ERROR_WARNING_HEADER_PREFFIX, ERROR_WARNING_HEADER_SUFFIX) {}
};

/**
 * Encabezados de tipo 'command'
 */
class CommandHeader : public Header {

	static const uint8_t COMMAND_HEADER_PREFFIX = 0x20;
	static const uint8_t COMMAND_HEADER_SUFFIX = 0x10;

	public:
		CommandHeader(int dataBlockSize):
			Header(dataBlockSize, COMMAND_HEADER_PREFFIX, COMMAND_HEADER_SUFFIX) {}
};

/**
 * Encabezados de tipo 'command reply'
 */
class CommandReplyHeader : public Header {

	static const uint8_t COMMAND_REPLY_HEADER_PREFFIX = 0x20;
	static const uint8_t COMMAND_REPLY_HEADER_SUFFIX = 0x20;

	public:
		CommandReplyHeader(int dataBlockSize):
			Header(dataBlockSize, COMMAND_REPLY_HEADER_PREFFIX, COMMAND_REPLY_HEADER_SUFFIX) {}
};

