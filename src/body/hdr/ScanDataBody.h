#ifndef SCANDATABODY_H_
#define SCANDATABODY_H_

#include "Body.h"

/**
 * Cuerpo del comando 'Scan Data'
 *
 * Solo se recupera del laser, no deberiamos instanciarlo
 */
class ScanDataBody : public Body {

	public:
		ScanDataBody(int bodySize, uint8_t * bodyBytes);

		bool isScanDataBody();

		std::string asText();
};

#endif /* SCANDATABODY_H_ */
