#ifndef SCANPOINT_H
#define SCANPOINT_H

#include <stdint.h> 	// para 'uint8_t'
#include <string>
#include <sstream>

/**
 * Clase basica con los elementos basicos del cuerpo de un mensaje
 */
class ScanPoint {

	public:

		ScanPoint(uint8_t data0, uint8_t data1, uint8_t data2, uint8_t data3, uint8_t data4, uint8_t data5, uint8_t data6, uint8_t data7);

		int getLayer();

		int getEcho();

		std::string getFlags();

		int getHorizontalAngle();

		int getRadialDistance();

		int getEchoPulseWidth();

		uint8_t* getBytesInRaw();

	protected:

		uint8_t byte0;
		uint8_t byte1;
		uint8_t byte2;
		uint8_t byte3;
		uint8_t byte4;
		uint8_t byte5;
		uint8_t byte6;
		uint8_t byte7;
};

#endif // SCANPOINT_H
