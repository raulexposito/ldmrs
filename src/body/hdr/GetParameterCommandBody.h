#ifndef GETPARAMETERREQUESTBODY_H
#define GETPARAMETERREQUESTBODY_H

#include "Body.h"
#include "../enum/ParameterEnum.h"

/**
 * Cuerpo del comando 'get parameter'
 */
class GetParameterCommandBody : public Body {

	public:

		GetParameterCommandBody(ParameterEnum parameter);

		int getAmountBytes();

		bool isGetParameterCommandBody();

		std::string asText();

	private:

		ParameterEnum parameter;

		void addParameterCode(ParameterEnum parameter);
};

#endif // GETPARAMETERREQUESTBODY_H
