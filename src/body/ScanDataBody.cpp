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

	amountPoints = bodyBytes[29] * 256 + bodyBytes[28];
	getPointCloud();
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
	std::vector<ScanPoint> pointCloud = getPointCloud();
	int i = 0;

	// LINEA 0

	std::stringstream fileName_0;
	std::stringstream measure_0;
	measure_0 << "Horizontal Angle" << ";" << "Radial Distance" << "\n";

	fileName_0 << filename << "_0_" << GENERIC_LOG_FILE_NAME;
	ofs.open(fileName_0.str().c_str());

	for (i = 0; i < amountPoints; i++) {
		ScanPoint currentPoint = pointCloud[i];
		if (currentPoint.getLayer() == 0) {
			measure_0 << currentPoint.getHorizontalAngle() << ";" << currentPoint.getRadialDistance() << "\n";
		}
	}
	ofs << measure_0.str();
	ofs.flush();
	ofs.close();

	// LINEA 1

	std::stringstream fileName_1;
	std::stringstream measure_1;
	measure_1 << "Horizontal Angle" << ";" << "Radial Distance" << "\n";

	fileName_1 << filename << "_1_" << GENERIC_LOG_FILE_NAME;
	ofs.open(fileName_1.str().c_str());

	for (i = 0; i < amountPoints; i++) {
		ScanPoint currentPoint = pointCloud[i];
		if (currentPoint.getLayer() == 1) {
			measure_1 << currentPoint.getHorizontalAngle() << ";" << currentPoint.getRadialDistance() << "\n";
		}
	}
	ofs << measure_1.str();
	ofs.flush();
	ofs.close();

	// LINEA 2
	std::stringstream fileName_2;
	std::stringstream measure_2;
	measure_2 << "Horizontal Angle" << ";" << "Radial Distance" << "\n";

	fileName_2 << filename << "_2_" << GENERIC_LOG_FILE_NAME;
	ofs.open(fileName_2.str().c_str());

	for (i = 0; i < amountPoints; i++) {
		ScanPoint currentPoint = pointCloud[i];
		if (currentPoint.getLayer() == 2) {
			measure_2 << currentPoint.getHorizontalAngle() << ";" << currentPoint.getRadialDistance() << "\n";
		}
	}
	ofs << measure_2.str();
	ofs.flush();
	ofs.close();

	// LINEA 3
	std::stringstream fileName_3;
	std::stringstream measure_3;
	measure_3 << "Horizontal Angle" << ";" << "Radial Distance" << "\n";

	fileName_3 << filename << "_3_" << GENERIC_LOG_FILE_NAME;
	ofs.open(fileName_3.str().c_str());

	for (i = 0; i < amountPoints; i++) {
		ScanPoint currentPoint = pointCloud[i];
		if (currentPoint.getLayer() == 3) {
			measure_3 << currentPoint.getHorizontalAngle() << ";" << currentPoint.getRadialDistance() << "\n";
		}
	}
	ofs << measure_3.str();
	ofs.flush();
	ofs.close();
}


std::string ScanDataBody::generateFilenamePointcloud () {
	struct timeval milliseconds;
	gettimeofday(&milliseconds, NULL);

	std::stringstream file;
	file <<	DateTime::getInstance()->getCurrentDate(NO_SEPARATOR) << "-" <<
			DateTime::getInstance()->getCurrentTime(NO_SEPARATOR) << "_" <<
			milliseconds.tv_usec;

	return file.str();
}
