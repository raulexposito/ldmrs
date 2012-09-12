#ifndef MESSAGE_H
#define MESSAGE_H

#include "../../header/hdr/Header.h"
#include "../../body/hdr/Body.h"
#include "../../header/enum/HeaderTypeEnum.h"
#include <stdint.h> 	// para 'uint8_t'
#include <string>
#include <sstream>

class Message {

	public:

		Message(Header* header, Body* body);

		virtual ~Message();

		Header* getHeader();

		Body* getBody();

		uint8_t * getBytesInRaw();

		virtual std::string asText();

		int getAmountBytes();

		bool isScanDataMessage();

		bool isErrorAndWarningMessage();

		bool isCommandMessage();

		bool isCommandReplyMessage();

		bool isGetParameterCommandMessage();

		bool isGetParameterCommandReplyMessage();

		bool isGetStatusCommandMessage();

		bool isGetStatusCommandReplyMessage();

		bool isResetCommandMessage();

		bool isSaveConfigCommandMessage();

		bool isSetNTPTimestampFracSecCommandMessage();

		bool isSetNTPTimestampFracSecCommandReplyMessage();

		bool isSetNTPTimestampSecCommandMessage();

		bool isSetNTPTimestampSecCommandReplyMessage();

		bool isSetParameterCommandMessage();

		bool isSetParameterCommandReplyMessage();

		bool isStartMeasureCommandMessage();

		bool isStopMeasureCommandMessage();

	protected:

		Header* header;

		Body* body;

	private:

		uint8_t* bytes;

		int messageSize;
};

#endif // MESSAGE_H
