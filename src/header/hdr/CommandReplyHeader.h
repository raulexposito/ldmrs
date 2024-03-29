#ifndef COMMANDREPLYHEADER_H_
#define COMMANDREPLYHEADER_H_

#include "Header.h"

/**
 * Encabezados de tipo 'command reply'
 */
class CommandReplyHeader : public Header {

	public:

		CommandReplyHeader(uint8_t * headerBytes);

		bool isCommandReplyHeader();

		std::string asText();
};

#endif /* COMMANDREPLYHEADER_H_ */
