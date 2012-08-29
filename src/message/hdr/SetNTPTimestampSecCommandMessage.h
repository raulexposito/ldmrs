#ifndef SETNTPTIMESTAMPSECREQUESTMESSAGE_H_
#define SETNTPTIMESTAMPSECREQUESTMESSAGE_H_

#include "Message.h"
#include <stdint.h> 	// para 'uint32_t'

/**
 * Mensajes de tipo 'SetNTPTimestampSecRequestMessage'
 */
class SetNTPTimestampSecCommandMessage : public Message {

	public:
		SetNTPTimestampSecCommandMessage(uint32_t seconds);
};

#endif /* SETNTPTIMESTAMPSECREQUESTMESSAGE_H_ */
