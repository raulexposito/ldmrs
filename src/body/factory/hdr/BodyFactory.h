#ifndef BODYFACTORY_H
#define BODYFACTORY_H

#include <stdint.h> 	// para 'uint8_t'
#include "../../../header/hdr/Header.h"
#include "../../../header/enum/HeaderTypeEnum.h"
#include "../../hdr/Body.h"
#include "../../enum/ParameterEnum.h"

class BodyFactory {

	public:

		static BodyFactory* getInstance();

		Body * generateBody (int bodySize, uint8_t * bodyBytes);

	private:

		BodyFactory(){};
		BodyFactory(BodyFactory const&){};
		static BodyFactory* instance;
		int bodySize;
};

#endif // BODYFACTORY_H
