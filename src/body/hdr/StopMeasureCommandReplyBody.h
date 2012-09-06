#ifndef STOPMEASURECOMMANDREPLYBODY_H
#define STOPMEASURECOMMANDREPLYBODY_H

#include "Body.h"

/**
 * Cuerpo del comando 'stop measure'
 */
class StopMeasureCommandReplyBody : public Body {

	public:
		StopMeasureCommandReplyBody(int bodySize, uint8_t * bodyBytes);

		bool isStopMeasureCommandReplyBody();

		std::string asText();
};

#endif // STOPMEASURECOMMANDREPLYBODY_H
