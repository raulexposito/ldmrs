#ifndef GETPARAMETERBODY_H
#define GETPARAMETERBODY_H

#include "Body.h"
#include "../enum/ParameterEnum.h"

/**
 * Cuerpo del comando 'get parameter'
 */
class GetParameterBody : public Body {

	public:
		GetParameterBody(ParameterEnum parameter);

	private:
		void addParameterCode(ParameterEnum parameter);
};

#endif // GETPARAMETERBODY_H
