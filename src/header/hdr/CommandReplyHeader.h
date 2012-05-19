#ifndef COMMANDREPLYHEADER_H_
#define COMMANDREPLYHEADER_H_

#include "Header.h"

/**
 * Encabezados de tipo 'command reply'
 */
class CommandReplyHeader : public Header {

	public:
		CommandReplyHeader(int dataBlockSize);

		CommandReplyHeader(uint8_t * headerBytes);

		virtual HeaderTypeEnum getType();
};

#endif /* COMMANDREPLYHEADER_H_ */
