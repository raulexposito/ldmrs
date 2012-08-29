#ifndef BODY_H
#define BODY_H

#include <stdint.h> 	// para 'uint8_t'
#include <string>
#include <sstream>

/**
 * Clase basica con los elementos basicos del cuerpo de un mensaje
 */
class Body {

	public:

		// empleado programaticamente para que los desarrolladores puedan crear encabezados
		// (generalmente de tipo COMMAND)
		Body(int bodySize, uint8_t preffix, uint8_t suffix);

		// empleado por la libreria para almacenar mensajes recibidos
		// (SCAN DATA, ERROR AND WARNING, COMMAND REPLY)
		Body(int bodySize, uint8_t * bodyBytes);

		virtual ~Body();

		uint8_t * getBytesInRaw();

		virtual std::string asText();

		virtual int getAmountBytes();

		virtual bool isGetParameterCommandBody();

		virtual bool isGetParameterCommandReplyBody();

		virtual bool isGetStatusCommandBody();

		virtual bool isGetStatusCommandReplyBody();

		virtual bool isResetCommandBody();

		virtual bool isSaveConfigCommandBody();

		virtual bool isSetNTPTimestampFracSecCommandBody();

		virtual bool isSetNTPTimestampFracSecCommandReplyBody();

		virtual bool isSetNTPTimestampSecCommandBody();

		virtual bool isSetNTPTimestampSecCommandReplyBody();

		virtual bool isSetParameterCommandBody();

		virtual bool isSetParameterCommandReplyBody();

		virtual bool isStartMeasureCommandBody();

		virtual bool isStopMeasureCommandBody();

		// TODO: incluir metodo toString() o similar con el que generar el log

	protected:

		uint8_t * bytes;

		int bodySize;
};

#endif // BODY_H
