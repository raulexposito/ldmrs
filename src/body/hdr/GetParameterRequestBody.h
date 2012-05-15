#ifndef GETPARAMETERREQUESTBODY_H
#define GETPARAMETERREQUESTBODY_H

#include "Body.h"
#include "../enum/ParameterEnum.h"

/**
 * Cuerpo del comando 'get parameter'
 */
class GetParameterRequestBody : public Body {

	public:
		GetParameterRequestBody(ParameterEnum parameter);

	private:
		void addParameterCode(ParameterEnum parameter);
};

#endif // GETPARAMETERREQUESTBODY_H
