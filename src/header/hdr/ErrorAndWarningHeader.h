#ifndef ERRORANDWARNINGHEADER_H_
#define ERRORANDWARNINGHEADER_H_

#include "Header.h"

/**
 * Encabezados de tipo 'error and warning'
 */
class ErrorAndWarningHeader : public Header {

	public:
		ErrorAndWarningHeader(uint8_t * headerBytes);

		bool isErrorAndWarningHeader();

		std::string asText();
};

#endif /* ERRORANDWARNINGHEADER_H_ */
