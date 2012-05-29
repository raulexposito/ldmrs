#ifndef STARTMEASUREBODY_H
#define STARTMEASUREBODY_H

#include "Body.h"

/**
 * Cuerpo del comando 'start measure'
 */
class StartMeasureBody : public Body {

	public:
		StartMeasureBody();

		virtual BodyTypeEnum getBodyType();
};

#endif // STARTMEASUREBODY_H
