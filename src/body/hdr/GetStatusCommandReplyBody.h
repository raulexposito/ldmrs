#ifndef GETSTATUSREPLYBODY_H
#define GETSTATUSREPLYBODY_H

#include "Body.h"

/**
 * Cuerpo del comando 'get status'
 *
 * Solo se recupera del laser, no deberiamos instanciarlo
 */
class GetStatusCommandReplyBody : public Body {

	public:

		GetStatusCommandReplyBody(int bodySize, uint8_t * bodyBytes);

		bool isGetStatusCommandReplyBody();

		std::string asText();

	private:

		std::string showHex8(uint8_t uint8);

		std::string showVersion(uint8_t first, uint8_t second);

		std::string scannerStatus(uint8_t n);

		float temperature(uint8_t first, uint8_t second);

		std::string calculateSerialNumber(uint8_t first, uint8_t second);

		int counterSerialNumber(uint8_t first, uint8_t second);

		std::string calculateTimestamp(uint8_t first, uint8_t second, uint8_t third, uint8_t forth, uint8_t fifth, uint8_t sixth);
};

#endif // GETSTATUSREPLYBODY_H
