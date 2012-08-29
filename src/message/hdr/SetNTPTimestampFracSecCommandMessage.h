#ifndef SETNTPTIMESTAMPFRACSECREQUESTMESSAGE_H_
#define SETNTPTIMESTAMPFRACSECREQUESTMESSAGE_H_

#include "Message.h"
#include <stdint.h> 	// para 'uint32_t'

/**
 * Mensajes de tipo 'SetNTPTimestampFracSecRequestMessage'
 */
class SetNTPTimestampFracSecCommandMessage : public Message {

	public:
		SetNTPTimestampFracSecCommandMessage(uint32_t frac_seconds);
};

#endif /* SETNTPTIMESTAMPFRACSECREQUESTMESSAGE_H_ */
