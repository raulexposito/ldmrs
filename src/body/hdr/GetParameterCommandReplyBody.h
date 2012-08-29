#ifndef GETPARAMETERREQUESTBODY_H
#define GETPARAMETERREQUESTBODY_H

#include "Body.h"
#include "../enum/ParameterEnum.h"

/**
 * Cuerpo del comando 'get parameter'
 *
 * Solo se recupera del laser, no deberiamos instanciarlo
 */
class GetParameterCommandReplyBody : public Body {

	public:
		GetParameterCommandReplyBody(int bodySize, uint8_t * bodyBytes);

		bool isGetParameterCommandReplyBody();

		std::string asText();
};

#endif // GETPARAMETERREQUESTBODY_H
