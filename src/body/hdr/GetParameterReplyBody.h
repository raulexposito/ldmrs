#ifndef GETPARAMETERREQUESTBODY_H
#define GETPARAMETERREQUESTBODY_H

#include "Body.h"
#include "../enum/ParameterEnum.h"

/**
 * Cuerpo del comando 'get parameter'
 */
class GetParameterReplyBody : public Body {

	public:
		GetParameterReplyBody(ParameterEnum parameter);

		virtual BodyTypeEnum getBodyType();
};

#endif // GETPARAMETERREQUESTBODY_H
