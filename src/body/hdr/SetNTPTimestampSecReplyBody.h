#ifndef SETNTPTIMESTAMPSECREPLYBODY_H
#define SETNTPTIMESTAMPSECREPLYBODY_H

#include "Body.h"
#include <stdint.h> 	// para 'uint32_t'

/**
 * Cuerpo del comando 'SetNTPTimestampSec'
 */
class SetNTPTimestampSecReplyBody : public Body {

	public:
		SetNTPTimestampSecReplyBody(uint32_t seconds);

		virtual BodyTypeEnum getBodyType();
};

#endif // SETNTPTIMESTAMPSECREPLYBODY_H
