#ifndef SETPARAMETERREPLYBODY_H
#define SETPARAMETERREPLYBODY_H

#include "Body.h"
#include "../enum/ParameterEnum.h"
#include <stdint.h> 	// para 'uint16_t'

/**
 * Cuerpo del comando 'set parameter'
 *
 * Solo se recupera del laser, no deberiamos instanciarlo
 */
class SetParameterCommandReplyBody : public Body {

	public:

		SetParameterCommandReplyBody(int bodySize, uint8_t * bodyBytes);

		bool isSetParameterCommandReplyBody();

		std::string asText();
};

#endif // SETPARAMETERREPLYBODY_H
