#ifndef STOPMEASUREBODY_H
#define STOPMEASUREBODY_H

#include "Body.h"

/**
 * Cuerpo del comando 'stop measure'
 */
class StopMeasureBody : public Body {

	public:
		StopMeasureBody();

		StopMeasureBody(int bodySize, uint8_t * bodyBytes);

		virtual BodyTypeEnum getBodyType();
};

#endif // STOPMEASUREBODY_H
