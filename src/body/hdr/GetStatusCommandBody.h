#ifndef GETSTATUSREQUESTBODY_H
#define GETSTATUSREQUESTBODY_H

#include "Body.h"

/**
 * Cuerpo del comando 'get status'
 */
class GetStatusCommandBody : public Body {

	public:

		GetStatusCommandBody();

		bool isGetStatusCommandBody();

		std::string asText();
};

#endif // GETSTATUSREQUESTBODY_H
