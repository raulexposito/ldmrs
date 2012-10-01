#ifndef STARTMEASURECOMMANDREPLYBODY_H
#define STARTMEASURECOMMANDREPLYBODY_H

#include "Body.h"

/**
 * Cuerpo del comando 'start measure'
 */
class StartMeasureCommandReplyBody : public Body {

	public:

		StartMeasureCommandReplyBody(int bodySize, uint8_t * bodyBytes);

		bool isStartMeasureCommandReplyBody();

		std::string asText();
};

#endif // STARTMEASURECOMMANDREPLYBODY_H
