#include "hdr/ScanDataBody.h"
#include "../util/hdr/BytesConverter.h"

ScanDataBody::ScanDataBody(int bodySize, uint8_t * bodyBytes):
		Body(bodySize, bodyBytes) {

	amountPoints = bodyBytes[28] * 256 + bodyBytes[29];
}

bool ScanDataBody::isScanDataBody() {
	return true;
}

std::vector<ScanPoint> ScanDataBody::getPointCloud() {
	std::vector<ScanPoint> pointCloud;

	int startPoint = 44;
	int i = 0;
	for (i = 0; i < amountPoints;i++) {
		ScanPoint * point = new ScanPoint(
				getBytesInRaw()[startPoint],
				getBytesInRaw()[startPoint + 1],
				getBytesInRaw()[startPoint + 2],
				getBytesInRaw()[startPoint + 3],
				getBytesInRaw()[startPoint + 4],
				getBytesInRaw()[startPoint + 5],
				getBytesInRaw()[startPoint + 6],
				getBytesInRaw()[startPoint + 7]);

		startPoint += 10;
		pointCloud.push_back(* point);
	}

	return pointCloud;
}

std::string ScanDataBody::asText() {
	std::stringstream text;
	text << "SCAN DATA" << " [";
	text << amountPoints << " points]";

	std::vector<ScanPoint> pointCloud = getPointCloud();
	int i = 0;
	for (i = 0; i < amountPoints; i++) {
		ScanPoint currentPoint = pointCloud[i];
		text << "\n"
			 <<	"[point " << (i+1) << "] "
			 << "\t" << currentPoint.getLayer() << "\t" << currentPoint.getEcho() << "\t" << currentPoint.getFlags()
		     << "\t" << currentPoint.getHorizontalAngle() << "\t" << currentPoint.getRadialDistance() << "\t" << currentPoint.getEchoPulseWidth()
		     << "\t" << currentPoint.getHorizontalAngle()
		     << "\t\t" << BytesConverter::getInstance()->toString(currentPoint.getBytesInRaw(), 8);
	}
	text << "\n";

	// TODO: si esta sincronizado, mostrar numero de puntos. Sino, indicar que esta desincronizado
	return text.str();
}
