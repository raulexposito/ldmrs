#ifndef SETNTPTIMESTAMPSECREPLYBODY_H
#define SETNTPTIMESTAMPSECREPLYBODY_H

#include "Body.h"
#include <stdint.h> 	// para 'uint32_t'

/**
 * Cuerpo del comando 'SetNTPTimestampSec'
 *
 * Solo se recupera del laser, no deberiamos instanciarlo
 */
class SetNTPTimestampSecCommandReplyBody : public Body {

	public:
		SetNTPTimestampSecCommandReplyBody(int bodySize, uint8_t * bodyBytes);

		bool isSetNTPTimestampSecCommandReplyBody();

		std::string asText();
};

#endif // SETNTPTIMESTAMPSECREPLYBODY_H
