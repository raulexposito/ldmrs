#ifndef ERRORANDWARNINGBODY_H_
#define ERRORANDWARNINGBODY_H_

#include "Body.h"

/**
 * Cuerpo del comando 'Error and Warning'
 *
 * Solo se recupera del laser, no deberiamos instanciarlo
 */
class ErrorAndWarningBody : public Body {

	public:
		ErrorAndWarningBody(int bodySize, uint8_t * bodyBytes);

		bool isErrorAndWarningBody();

		std::string asText();
};

#endif /* ERRORANDWARNINGBODY_H_ */
