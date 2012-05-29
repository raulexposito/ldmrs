#ifndef SETPARAMETERREPLYBODY_H
#define SETPARAMETERREPLYBODY_H

#include "Body.h"
#include "../enum/ParameterEnum.h"
#include <stdint.h> 	// para 'uint16_t'

/**
 * Cuerpo del comando 'set parameter'
 */
class SetParameterReplyBody : public Body {

	public:
		SetParameterReplyBody(ParameterEnum parameter);

		virtual BodyTypeEnum getBodyType();
};

#endif // SETPARAMETERREPLYBODY_H