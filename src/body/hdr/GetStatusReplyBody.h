#ifndef GETSTATUSREPLYBODY_H
#define GETSTATUSREPLYBODY_H

#include "Body.h"

/**
 * Cuerpo del comando 'get status'
 */
class GetStatusReplyBody : public Body {

	public:
		GetStatusReplyBody();

		virtual BodyTypeEnum getBodyType();
};

#endif // GETSTATUSREPLYBODY_H