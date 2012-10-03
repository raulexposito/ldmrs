#ifndef SAVECONFIGBODY_H
#define SAVECONFIGBODY_H

#include "Body.h"

/**
 * Cuerpo del comando 'save config'
 */
class SaveConfigCommandBody : public Body {

	public:

		SaveConfigCommandBody();

		bool isSaveConfigCommandBody();

		std::string asText();
};

#endif // SAVECONFIGBODY_H
