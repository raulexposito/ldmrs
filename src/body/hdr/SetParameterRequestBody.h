#ifndef SETPARAMETERREQUESTBODY_H
#define SETPARAMETERREQUESTBODY_H

#include "Body.h"
#include "../enum/ParameterEnum.h"
#include <stdint.h> 	// para 'uint16_t'

/**
 * Cuerpo del comando 'set parameter'
 */
class SetParameterRequestBody : public Body {

	public:
		SetParameterRequestBody(ParameterEnum parameter, uint32_t value);

	private:
		void addParameterCode(ParameterEnum parameter);
		void addUINT32ParameterValue(uint32_t value);
		void addUINT16ParameterValue(uint32_t value);
};

#endif // SETPARAMETERREQUESTBODY_H
