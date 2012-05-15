#ifndef SETNTPTIMESTAMPFRACSECREQUESTBODY_H
#define SETNTPTIMESTAMPFRACSECREQUESTBODY_H

#include "Body.h"
#include <stdint.h> 	// para 'uint32_t'

/**
 * Cuerpo del comando 'SetNTPTimestampFracSec'
 */
class SetNTPTimestampFracSecRequestBody : public Body {

	public:
		SetNTPTimestampFracSecRequestBody(uint32_t frac_seconds);
};

#endif // SETNTPTIMESTAMPFRACSECREQUESTBODY_H
