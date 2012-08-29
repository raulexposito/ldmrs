#ifndef SCANDATAHEADER_H
#define SCANDATAHEADER_H

#include "Header.h"

/**
 * Encabezados de tipo 'scan data'
 */
class ScanDataHeader : public Header {

	public:
		ScanDataHeader(uint8_t * headerBytes);

		bool isScanDataHeader();

		std::string asText();
};

#endif // SCANDATAHEADER_H

