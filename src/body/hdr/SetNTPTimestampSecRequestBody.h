#ifndef SETNTPTIMESTAMPSECREQUESTBODY_H
#define SETNTPTIMESTAMPSECREQUESTBODY_H

#include "Body.h"
#include <stdint.h> 	// para 'uint32_t'

/**
 * Cuerpo del comando 'SetNTPTimestampSec'
 */
class SetNTPTimestampSecRequestBody : public Body {

	public:
		SetNTPTimestampSecRequestBody(uint32_t seconds);

		virtual BodyTypeEnum getBodyType();
};

#endif // SETNTPTIMESTAMPSECREQUESTBODY_H
