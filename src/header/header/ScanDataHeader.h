#ifndef SCANDATAHEADER_H
#define SCANDATAHEADER_H

#include "Header.h"

/**
 * Encabezados de tipo 'scan data'
 */
class ScanDataHeader : public Header {

	public:
		ScanDataHeader(int dataBlockSize);
};

#endif // SCANDATAHEADER_H
