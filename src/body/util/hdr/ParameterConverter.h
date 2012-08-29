#ifndef PARAMETERCONVERTER_H
#define PARAMETERCONVERTER_H

#include "../../enum/ParameterEnum.h"
#include <stdint.h> 	// para 'uint8_t'
#include <string>
#include <sstream>

class ParameterConverter {

	public:
		static ParameterConverter* getInstance();

		void parameterToHex(ParameterEnum parameter, uint8_t & preffix, uint8_t & suffix);

		std::string parameterToText(ParameterEnum parameter);

	private:

		ParameterConverter(){};
		ParameterConverter(ParameterConverter const&){};
		static ParameterConverter* instance;
};

#endif // PARAMETERCONVERTER_H
