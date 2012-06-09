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

		SetParameterReplyBody(int bodySize, uint8_t * bodyBytes);

		virtual BodyTypeEnum getBodyType();
};

#endif // SETPARAMETERREPLYBODY_H
