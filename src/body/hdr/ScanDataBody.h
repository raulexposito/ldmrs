#ifndef SCANDATABODY_H_
#define SCANDATABODY_H_

#include "Body.h"
#include "../scanpoint/hdr/ScanPoint.h"
#include <vector>
#include <fstream>
#include <iostream>

using std::ostream;
using std::ofstream;
using std::cout;

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

		std::string generateFilenamePointcloud();

		int getAmountPoints();

		std::string showPoints();

		void savePoints();

	private:

		int amountPoints;
		ofstream ofs;
};

#endif /* SCANDATABODY_H_ */
