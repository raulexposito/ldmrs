#ifndef SCANDATABODY_H_
#define SCANDATABODY_H_

#include "Body.h"
#include "../scanpoint/hdr/ScanPoint.h"
#include <vector>

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

		std::vector<ScanPoint> getPointCloud();

		int getAmountPoints();

	private:
		int amountPoints;

};

#endif /* SCANDATABODY_H_ */
