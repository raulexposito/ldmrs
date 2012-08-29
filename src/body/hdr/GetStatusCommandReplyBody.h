#ifndef GETSTATUSREPLYBODY_H
#define GETSTATUSREPLYBODY_H

#include "Body.h"

/**
 * Cuerpo del comando 'get status'
 *
 * Solo se recupera del laser, no deberiamos instanciarlo
 */
class GetStatusCommandReplyBody : public Body {

	public:
		GetStatusCommandReplyBody(int bodySize, uint8_t * bodyBytes);

		bool isGetStatusCommandReplyBody();

		std::string asText();
};

#endif // GETSTATUSREPLYBODY_H
