#ifndef STOPMEASUREBODY_H
#define STOPMEASUREBODY_H

#include "Body.h"

/**
 * Cuerpo del comando 'stop measure'
 */
class StopMeasureBody : public Body {

	public:
		StopMeasureBody();

		virtual BodyTypeEnum getBodyType();
};

#endif // STOPMEASUREBODY_H
