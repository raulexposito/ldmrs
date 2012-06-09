#ifndef SAVECONFIGBODY_H
#define SAVECONFIGBODY_H

#include "Body.h"

/**
 * Cuerpo del comando 'save config'
 */
class SaveConfigBody : public Body {

	public:
		SaveConfigBody();

		SaveConfigBody(int bodySize, uint8_t * bodyBytes);

		virtual BodyTypeEnum getBodyType();
};

#endif // SAVECONFIGBODY_H
