#ifndef SETNTPTIMESTAMPSECREQUESTBODY_H
#define SETNTPTIMESTAMPSECREQUESTBODY_H

#include "Body.h"
#include <stdint.h> 	// para 'uint32_t'

/**
 * Cuerpo del comando 'SetNTPTimestampSec'
 */
class SetNTPTimestampSecCommandBody : public Body {

	public:
		SetNTPTimestampSecCommandBody(uint32_t seconds);

		bool isSetNTPTimestampSecCommandBody();

		std::string asText();
};

#endif // SETNTPTIMESTAMPSECREQUESTBODY_H
