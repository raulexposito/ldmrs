#ifndef RESETBODY_H
#define RESETBODY_H

#include "Body.h"

/**
 * Cuerpo del comando 'reset'
 */
class ResetCommandBody : public Body {

	public:
		ResetCommandBody();

		bool isResetCommandBody();

		std::string asText();
};

#endif // RESETBODY_H
