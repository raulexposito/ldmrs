#ifndef SAVECONFIGCOMMANDREPLYBODY_H_
#define SAVECONFIGCOMMANDREPLYBODY_H_

#include "Body.h"

/**
 * Cuerpo del comando 'get status'
 *
 * Solo se recupera del laser, no deberiamos instanciarlo
 */
class SaveConfigCommandReplyBody : public Body {

	public:

		SaveConfigCommandReplyBody(int bodySize, uint8_t * bodyBytes);

		bool isSaveConfigCommandReplyBody();

		std::string asText();
};

#endif /* SAVECONFIGCOMMANDREPLYBODY_H_ */
