#ifndef STOPMEASUREBODY_H
#define STOPMEASUREBODY_H

#include "Body.h"

/**
 * Cuerpo del comando 'stop measure'
 */
class StopMeasureCommandBody : public Body {

	public:

		StopMeasureCommandBody();

		bool isStopMeasureCommandBody();

		std::string asText();
};

#endif // STOPMEASUREBODY_H
