#ifndef BODYFACTORY_H
#define BODYFACTORY_H

#include <stdint.h> 	// para 'uint8_t'
#include "../../../header/hdr/Header.h"
#include "../../../header/enum/HeaderTypeEnum.h"
#include "../../hdr/Body.h"
#include "../../enum/ParameterEnum.h"

/**
 * Clase encargada de generar cuerpos de mensajes con el flujo de bytes
 * que reciba
 */
class BodyFactory {

	public:

		static BodyFactory* getInstance();

		Body * generateBody (Header * header, uint8_t * bodyBytes);

	private:

		BodyFactory(){};

		BodyFactory(BodyFactory const&){};

		static BodyFactory* instance;

		int bodySize;

		Body* generateCommandReplyBody(int bodySize, uint8_t * bodyBytes);
};

#endif // BODYFACTORY_H
