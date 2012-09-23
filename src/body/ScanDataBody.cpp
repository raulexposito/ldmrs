#include "hdr/ScanDataBody.h"
#include "../util/hdr/BytesConverter.h"
#include "../util/hdr/DateTime.h"
#include "../config/hdr/Configuration.h"
#include <sys/time.h>
#include <sstream>


#define GENERIC_LOG_FILE_NAME "pointcloud.csv"

#define NO_SEPARATOR ""

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

	if (Configuration::getInstance()->isShowPointCloud()) {
		text << showPoints();
	}

	if (Configuration::getInstance()->isRecordPointCloud()) {
		savePoints();
	}

	return text.str();
}

std::string ScanDataBody::showPoints() {
	std::stringstream text;
	text << "\npoint \tlayer \techo \tflags \t\thoriz angle \tradial distance \techo width \tbytes" << std::endl;
	std::vector<ScanPoint> pointCloud = getPointCloud();
	int i = 0;
	for (i = 0; i < amountPoints; i++) {
		ScanPoint currentPoint = pointCloud[i];
		text
		 <<	(i+1) << "\t"
		 << currentPoint.getLayer() << "\t"
		 << currentPoint.getEcho() << "\t"
		 << currentPoint.getFlags() << "\t"
		 << currentPoint.getHorizontalAngle() << "\t\t"
		 << currentPoint.getRadialDistance() << "\t\t\t"
		 << currentPoint.getEchoPulseWidth() << "\t\t"
		 << BytesConverter::getInstance()->toString(currentPoint.getBytesInRaw(), 8)
		 << std::endl;
	}
	text << "\n";
	return text.str();
}

void ScanDataBody::savePoints() {
	std::string filename = generateFilenamePointcloud();
	ofs.open(filename.c_str());
	std::vector<ScanPoint> pointCloud = getPointCloud();

	int i = 0;
	for (i = 0; i < amountPoints; i++) {
		ScanPoint currentPoint = pointCloud[i];
		ofs << currentPoint.getRadialDistance() << ";";
	}
	ofs.flush();
}


std::string ScanDataBody::generateFilenamePointcloud () {
	struct timeval milliseconds;
	gettimeofday(&milliseconds, NULL);

	std::stringstream file;
	file <<	DateTime::getInstance()->getCurrentDate(NO_SEPARATOR) << "-" <<
			DateTime::getInstance()->getCurrentTime(NO_SEPARATOR) << "_" <<
			milliseconds.tv_usec << "_" << GENERIC_LOG_FILE_NAME;

	return file.str();
}
