#ifndef BODYFACTORY_H
#define BODYFACTORY_H

#include <stdint.h> 	// para 'uint8_t'
#include "../../../header/hdr/Header.h"
#include "../../../header/enum/HeaderTypeEnum.h"
#include "../../hdr/Body.h"
#include "../../enum/ParameterEnum.h"

class BodyFactory {

	public:

		static BodyFactory* getInstance();

		Body * generateBody (HeaderTypeEnum headerType, uint8_t * bodyBytes);

	private:

		BodyFactory(){};
		BodyFactory(BodyFactory const&){};
		static BodyFactory* instance;
		int bodySize;

		bool isReset(uint8_t * bodyBytes);
		bool isGetStatus(uint8_t * bodyBytes);
		bool isSaveConfig(uint8_t * bodyBytes);
		bool isSetParameter(uint8_t * bodyBytes);
		bool isGetParameter(uint8_t * bodyBytes);
		bool isStartMeasure(uint8_t * bodyBytes);
		bool isStopMeasure(uint8_t * bodyBytes);
		bool isSetNTPTimestampSec(uint8_t * bodyBytes);
		bool isSetNTPTimestampFracSec(uint8_t * bodyBytes);

		ParameterEnum getParameter(uint8_t * bodyBytes);
		bool isIpAddress(uint8_t * bodyBytes);
		bool isTcpPort(uint8_t * bodyBytes);
		bool isSubnetMask(uint8_t * bodyBytes);
		bool isStandardGateway(uint8_t * bodyBytes);
		bool isDataOutputFlag(uint8_t * bodyBytes);
		bool isStartAngle(uint8_t * bodyBytes);
		bool isEndAngle(uint8_t * bodyBytes);
		bool isScanFrecuency(uint8_t * bodyBytes);
		bool isSyncAngleOffset(uint8_t * bodyBytes);
		bool isAngularResolutionType(uint8_t * bodyBytes);
};

#endif // BODYFACTORY_H
