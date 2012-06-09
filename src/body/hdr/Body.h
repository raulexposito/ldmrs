#ifndef BODY_H
#define BODY_H

#include <stdint.h> 	// para 'uint8_t'
#include "../enum/BodyTypeEnum.h"


/**
 * Clase basica con los elementos basicos del cuerpo de un mensaje
 */
class Body {

	public:

		Body(int bodySize, uint8_t preffix, uint8_t suffix);

		Body(int bodySize, uint8_t * bodyBytes);

		virtual ~Body();

		uint8_t * getBytes();

		virtual int getAmountBytes();

		void showBytes();

	protected:

		uint8_t * bytes;

		int bodySize;
};

#endif // BODY_H
