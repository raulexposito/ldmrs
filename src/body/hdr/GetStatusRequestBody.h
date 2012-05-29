#ifndef GETSTATUSREQUESTBODY_H
#define GETSTATUSREQUESTBODY_H

#include "Body.h"

/**
 * Cuerpo del comando 'get status'
 */
class GetStatusRequestBody : public Body {

	public:
		GetStatusRequestBody();

		virtual BodyTypeEnum getBodyType();
};

#endif // GETSTATUSREQUESTBODY_H
