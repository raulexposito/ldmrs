#include "hdr/ErrorAndWarningBody.h"

ErrorAndWarningBody::ErrorAndWarningBody(int bodySize, uint8_t * bodyBytes):
		Body(bodySize, bodyBytes) {
}

bool ErrorAndWarningBody::isErrorAndWarningBody() {
	return true;
}

std::string ErrorAndWarningBody::asText() {
	std::stringstream text;
	text << "ERROR AND WARNING -> ";
	// Error register 1

	if (getBytesInRaw()[1] & 0x00000001) { text << "message: Contact support, "; }
	if (getBytesInRaw()[1] & 0x00000010) { text << "message: Contact support, "; }
	if (getBytesInRaw()[1] & 0x00000100) { text << "message: Scan buffered transmitted incompletely, decrease scan resolution/frecuency/range; contact support, "; }
	if (getBytesInRaw()[1] & 0x00001000) { text << "message: Scan buffer overflow, decrease scan resolution/frecuency/range; contact support, "; }
	if (getBytesInRaw()[1] & 0x00010000) { text << "message: Contact support, "; }
	if (getBytesInRaw()[1] & 0x00100000) { text << "message: Reserved, "; }
	if (getBytesInRaw()[1] & 0x01000000) { text << "message: Reserved, "; }
	if (getBytesInRaw()[1] & 0x10000000) { text << "message: Reserved, "; }

	if (getBytesInRaw()[0] & 0x00000001) { text << "message: ADP Under Temperature, provide heating, "; }
	if (getBytesInRaw()[0] & 0x00000010) { text << "message: ADP Over Temperature, provide cooling, "; }
	if ((getBytesInRaw()[0] & 0x00000010) && (getBytesInRaw()[0] & 0x00000001)) { text << "message: APD Temperature Sensor defect, contact support";}
	if (getBytesInRaw()[0] & 0x00000010) { text << "message: Contact support, "; }
	if (getBytesInRaw()[0] & 0x00001000) { text << "message: Contact support, "; }
	if (getBytesInRaw()[0] & 0x00010000) { text << "message: Contact support, "; }
	if (getBytesInRaw()[0] & 0x00100000) { text << "message: Contact support, "; }
	if (getBytesInRaw()[0] & 0x01000000) { text << "message: Reserved, "; }
	if (getBytesInRaw()[0] & 0x10000000) { text << "message: Reserved, "; }

	// Error register 2
	if (getBytesInRaw()[2] & 0x00000001) { text << "message: Contact support, "; }
	if (getBytesInRaw()[2] & 0x00000010) { text << "message: Contact support, "; }
	if (getBytesInRaw()[2] & 0x00000100) { text << "message: Contact support, "; }
	if (getBytesInRaw()[2] & 0x00001000) { text << "message: Contact support, "; }
	if (getBytesInRaw()[2] & 0x00010000) { text << "message: Incorrect configuration data, load correct configuration values, "; }
	if (getBytesInRaw()[2] & 0x00100000) { text << "message: Configuration contains incorrect parameters, load correct configuration values, "; }
	if (getBytesInRaw()[2] & 0x01000000) { text << "message: Data processing timeout, decrease scan resolutiuon or scan frecuency, "; }
	if (getBytesInRaw()[2] & 0x10000000) { text << "message: Contact support, "; }
	if (getBytesInRaw()[2] & 0x00000001) { text << "message: Reserved, "; }
	if (getBytesInRaw()[2] & 0x00000010) { text << "message: Reserved, "; }
	if (getBytesInRaw()[2] & 0x00000100) { text << "message: Reserved, "; }
	if (getBytesInRaw()[2] & 0x00001000) { text << "message: Reserved, "; }
	if (getBytesInRaw()[2] & 0x00010000) { text << "message: Reserved, "; }
	if (getBytesInRaw()[2] & 0x00100000) { text << "message: Reserved, "; }
	if (getBytesInRaw()[2] & 0x01000000) { text << "message: Reserved, "; }
	if (getBytesInRaw()[2] & 0x10000000) { text << "message: Reserved, "; }

	// Warning register 1
	if (getBytesInRaw()[5] & 0x00000001) { text << "message: Internal communication error, "; }
	if (getBytesInRaw()[5] & 0x00000010) { text << "message: Internal warning, "; }
	if (getBytesInRaw()[5] & 0x00000100) { text << "message: Internal warning, "; }
	if (getBytesInRaw()[5] & 0x00001000) { text << "message: Warning temperature very low, "; }
	if (getBytesInRaw()[5] & 0x00010000) { text << "message: Warning temperature very high, "; }
	if (getBytesInRaw()[5] & 0x00100000) { text << "message: Internal warning, "; }
	if (getBytesInRaw()[5] & 0x01000000) { text << "message: Internal warning, "; }
	if (getBytesInRaw()[5] & 0x10000000) { text << "message: Synchronization error, check synchronization and scan frecuency, "; }
	if (getBytesInRaw()[4] & 0x00000001) { text << "message: Reserved, "; }
	if (getBytesInRaw()[4] & 0x00000010) { text << "message: Reserved, "; }
	if (getBytesInRaw()[4] & 0x00000100) { text << "message: Reserved, "; }
	if (getBytesInRaw()[4] & 0x00001000) { text << "message: Reserved, "; }
	if (getBytesInRaw()[4] & 0x00010000) { text << "message: Reserved, "; }
	if (getBytesInRaw()[4] & 0x00100000) { text << "message: Reserved, "; }
	if (getBytesInRaw()[4] & 0x01000000) { text << "message: Reserved, "; }
	if (getBytesInRaw()[4] & 0x10000000) { text << "message: Reserved, "; }

	// Warning register 2
	if (getBytesInRaw()[7] & 0x00000001) { text << "message: Reserved, "; }
	if (getBytesInRaw()[7] & 0x00000010) { text << "message: Ethernet Interface blocked, check Ethernet connection, "; }
	if (getBytesInRaw()[7] & 0x00001000) { text << "message: Contact support, "; }
	if (getBytesInRaw()[7] & 0x00010000) { text << "message: Error receiving Ethernet data, check Ethernet conection/data, "; }
	if (getBytesInRaw()[7] & 0x00100000) { text << "message: Incorrect or forbidden command received, check command, "; }
	if (getBytesInRaw()[7] & 0x01000000) { text << "message: Memory access failure, restart LD-MRS, contact support, "; }
	if (getBytesInRaw()[7] & 0x10000000) { text << "message: Reserved, "; }
	if (getBytesInRaw()[6] & 0x00000001) { text << "message: Reserved, "; }
	if (getBytesInRaw()[6] & 0x00000010) { text << "message: Reserved, "; }
	if (getBytesInRaw()[6] & 0x00000100) { text << "message: Reserved, "; }
	if (getBytesInRaw()[6] & 0x00001000) { text << "message: Reserved, "; }
	if (getBytesInRaw()[6] & 0x00010000) { text << "message: Reserved, "; }
	if (getBytesInRaw()[6] & 0x00100000) { text << "message: Reserved, "; }
	if (getBytesInRaw()[6] & 0x01000000) { text << "message: Reserved, "; }
	if (getBytesInRaw()[6] & 0x10000000) { text << "message: Reserved, "; }
	return text.str();
}
