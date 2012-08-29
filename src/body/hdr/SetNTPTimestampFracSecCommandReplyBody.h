#ifndef SETNTPTIMESTAMPFRACSECREPLYBODY_H
#define SETNTPTIMESTAMPFRACSECREPLYBODY_H

#include "Body.h"
#include <stdint.h> 	// para 'uint32_t'

/**
 * Cuerpo del comando 'SetNTPTimestampFracSec'
 *
 * Solo se recupera del laser, no deberiamos instanciarlo
 */
class SetNTPTimestampFracSecCommandReplyBody : public Body {

	public:
		SetNTPTimestampFracSecCommandReplyBody(int bodySize, uint8_t * bodyBytes);

		bool isSetNTPTimestampFracSecCommandReplyBody();

		std::string asText();
};

#endif // SETNTPTIMESTAMPFRACSECREPLYBODY_H
