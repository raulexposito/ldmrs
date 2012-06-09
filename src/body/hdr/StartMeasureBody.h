#ifndef STARTMEASUREBODY_H
#define STARTMEASUREBODY_H

#include "Body.h"

/**
 * Cuerpo del comando 'start measure'
 */
class StartMeasureBody : public Body {

	public:
		StartMeasureBody();

		StartMeasureBody(int bodySize, uint8_t * bodyBytes);

		virtual BodyTypeEnum getBodyType();
};

#endif // STARTMEASUREBODY_H
