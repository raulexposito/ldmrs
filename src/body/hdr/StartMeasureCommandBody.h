#ifndef STARTMEASUREBODY_H
#define STARTMEASUREBODY_H

#include "Body.h"

/**
 * Cuerpo del comando 'start measure'
 */
class StartMeasureCommandBody : public Body {

	public:

		StartMeasureCommandBody();

		bool isStartMeasureCommandBody();

		std::string asText();
};

#endif // STARTMEASUREBODY_H
