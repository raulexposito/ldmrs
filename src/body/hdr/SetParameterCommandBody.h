#ifndef SETPARAMETERREQUESTBODY_H
#define SETPARAMETERREQUESTBODY_H

#include "Body.h"
#include "../enum/ParameterEnum.h"
#include <stdint.h> 	// para 'uint16_t'

/**
 * Cuerpo del comando 'set parameter'
 */
class SetParameterCommandBody : public Body {

	public:
		SetParameterCommandBody(ParameterEnum parameter, uint32_t value);

		int getAmountBytes();

		bool isSetParameterCommandBody();

		std::string asText();

	private:
		void addParameterCode(ParameterEnum parameter);
		void addUINT32ParameterValue(uint32_t value);
		void addUINT16ParameterValue(uint32_t value);
};

#endif // SETPARAMETERREQUESTBODY_H
