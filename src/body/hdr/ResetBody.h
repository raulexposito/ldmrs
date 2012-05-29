#ifndef RESETBODY_H
#define RESETBODY_H

#include "Body.h"

/**
 * Cuerpo del comando 'reset'
 */
class ResetBody : public Body {

	public:
		ResetBody();

		virtual BodyTypeEnum getBodyType();
};

#endif // RESETBODY_H
