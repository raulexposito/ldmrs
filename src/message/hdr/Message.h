#ifndef MESSAGE_H
#define MESSAGE_H

#include "../../header/hdr/Header.h"
#include "../../body/hdr/Body.h"
#include "../../header/enum/HeaderTypeEnum.h"
#include <stdint.h> 	// para 'uint8_t'
#include <string>

class Message {

	public:

		Message(Header* header, Body* body);

		virtual ~Message();

		Header* getHeader();

		Body* getBody();

		uint8_t * getBytesInRaw();

		int getAmountBytes();

		bool isScanDataMessage();

		bool isErrorAndWarningMessage();

		bool isCommandMessage();

		bool isCommandReplyMessage();

	protected:

		Header* header;

		Body* body;

	private:

		uint8_t* bytes;

		int messageSize;

		void showHeaderDataType(HeaderTypeEnum headerType, Body* body);

		void showScanData(Body* body);

		void showPointMeasurement(int number, int pointBodyPosition, Body* body);

		void showErrorsAndWarnings(Body* body);

		void showHeaderSubDataType(Body* body, bool isCommandReply);

		bool showParameterType(Body* body, int parameterFirstPosition, int parameterSecondPosition);

		void showParameterValue(Body* body, int initPosition, int endPosition, bool isAddress);

		void showGetStatus(Body* body);

		void showHex8(uint8_t uint8);
};

#endif // MESSAGE_H
