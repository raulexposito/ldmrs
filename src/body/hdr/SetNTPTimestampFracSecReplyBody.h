#ifndef SETNTPTIMESTAMPFRACSECREPLYBODY_H
#define SETNTPTIMESTAMPFRACSECREPLYBODY_H

#include "Body.h"
#include <stdint.h> 	// para 'uint32_t'

/**
 * Cuerpo del comando 'SetNTPTimestampFracSec'
 */
class SetNTPTimestampFracSecReplyBody : public Body {

	public:
	SetNTPTimestampFracSecReplyBody(uint32_t frac_seconds);

		virtual BodyTypeEnum getBodyType();
};

#endif // SETNTPTIMESTAMPFRACSECREPLYBODY_H