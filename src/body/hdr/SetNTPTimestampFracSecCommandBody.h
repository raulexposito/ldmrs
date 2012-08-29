#ifndef SETNTPTIMESTAMPFRACSECREQUESTBODY_H
#define SETNTPTIMESTAMPFRACSECREQUESTBODY_H

#include "Body.h"
#include <stdint.h> 	// para 'uint32_t'

/**
 * Cuerpo del comando 'SetNTPTimestampFracSec'
 */
class SetNTPTimestampFracSecCommandBody : public Body {

	public:
		SetNTPTimestampFracSecCommandBody(uint32_t frac_seconds);

		bool isSetNTPTimestampFracSecCommandBody();

		std::string asText();
};

#endif // SETNTPTIMESTAMPFRACSECREQUESTBODY_H
