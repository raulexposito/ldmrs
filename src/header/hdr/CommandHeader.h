#ifndef COMMANDHEADER_H_
#define COMMANDHEADER_H_

#include "Header.h"

/**
 * Encabezados de tipo 'command'
 */
class CommandHeader : public Header {

	public:
		CommandHeader(int dataBlockSize);

		bool isCommandHeader();
};

#endif /* COMMANDHEADER_H_ */
