#ifndef SETNTPTIMESTAMPSECREQUESTMESSAGE_H_
#define SETNTPTIMESTAMPSECREQUESTMESSAGE_H_

#include "Message.h"
#include <stdint.h> 	// para 'uint32_t'

/**
 * Mensajes de tipo 'SetNTPTimestampSecRequestMessage'
 */
class SetNTPTimestampSecRequestMessage : public Message {

	public:
		SetNTPTimestampSecRequestMessage(uint32_t seconds);
};

#endif /* SETNTPTIMESTAMPSECREQUESTMESSAGE_H_ */
