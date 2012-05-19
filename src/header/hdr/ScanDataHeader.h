#ifndef SCANDATAHEADER_H
#define SCANDATAHEADER_H

#include "Header.h"

/**
 * Encabezados de tipo 'scan data'
 */
class ScanDataHeader : public Header {

	public:
		ScanDataHeader(int dataBlockSize);

		ScanDataHeader(uint8_t * headerBytes);

		virtual HeaderTypeEnum getType();
};

#endif // SCANDATAHEADER_H

