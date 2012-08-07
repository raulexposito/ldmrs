#ifndef BODY_H
#define BODY_H

#include <stdint.h> 	// para 'uint8_t'
#include "../enum/BodyTypeEnum.h"


/**
 * Clase basica con los elementos basicos del cuerpo de un mensaje
 */
class Body {

	public:

		// empleado programaticamente para que los desarrolladores puedan crear encabezados
		// (generalmente de COMMAND)
		Body(int bodySize, uint8_t preffix, uint8_t suffix);

		// empleado por la libreria para almacenar mensajes recibidos
		// (SCAN DATA, ERROR AND WARNING, COMMAND REPLY)
		Body(int bodySize, uint8_t * bodyBytes);

		virtual ~Body();

		uint8_t * getBytesInRaw();

		virtual int getAmountBytes();

	protected:

		uint8_t * bytes;

		int bodySize;
};

#endif // BODY_H
