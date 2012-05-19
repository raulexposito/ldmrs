#ifndef ERRORANDWARNINGHEADER_H_
#define ERRORANDWARNINGHEADER_H_

#include "Header.h"

/**
 * Encabezados de tipo 'error and warning'
 */
class ErrorAndWarningHeader : public Header {

	public:
		ErrorAndWarningHeader(int dataBlockSize);

		ErrorAndWarningHeader(uint8_t * headerBytes);

		virtual HeaderTypeEnum getType();
};

#endif /* ERRORANDWARNINGHEADER_H_ */
