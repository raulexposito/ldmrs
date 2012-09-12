#include "hdr/ErrorAndWarningBody.h"

ErrorAndWarningBody::ErrorAndWarningBody(int bodySize, uint8_t * bodyBytes):
		Body(bodySize, bodyBytes) {
}

bool ErrorAndWarningBody::isErrorAndWarningBody() {
	return true;
}

std::string ErrorAndWarningBody::asText() {
	std::stringstream text;
	text << "ERROR AND WARNING" << "[";
	text << getAmountBytes() << "]";
	// Error register 1

	if (getBytesInRaw()[1] & 0x00000001) { text << "\tmessage: Contact support"; }
	if (getBytesInRaw()[1] & 0x00000010) { text << "\tmessage: Contact support"; }
	if (getBytesInRaw()[1] & 0x00000100) { text << "\tmessage: Scan buffered transmitted incompletely, decrease scan resolution/frecuency/range; contact support"; }
	if (getBytesInRaw()[1] & 0x00001000) { text << "\tmessage: Scan buffer overflow, decrease scan resolution/frecuency/range; contact support"; }
	if (getBytesInRaw()[1] & 0x00010000) { text << "\tmessage: Contact support"; }
	if (getBytesInRaw()[1] & 0x00100000) { text << "\tmessage: Reserved"; }
	if (getBytesInRaw()[1] & 0x01000000) { text << "\tmessage: Reserved"; }
	if (getBytesInRaw()[1] & 0x10000000) { text << "\tmessage: Reserved"; }

	if (getBytesInRaw()[0] & 0x00000001) { text << "\tmessage: ADP Under Temperature, provide heating"; }
	if (getBytesInRaw()[0] & 0x00000010) { text << "\tmessage: ADP Over Temperature, provide cooling"; }
	if ((getBytesInRaw()[0] & 0x00000010) && (getBytesInRaw()[0] & 0x00000001)) { text << "\tmessage: APD Temperature Sensor defect, contact support";}
	if (getBytesInRaw()[0] & 0x00000010) { text << "\tmessage: Contact support"; }
	if (getBytesInRaw()[0] & 0x00001000) { text << "\tmessage: Contact support"; }
	if (getBytesInRaw()[0] & 0x00010000) { text << "\tmessage: Contact support"; }
	if (getBytesInRaw()[0] & 0x00100000) { text << "\tmessage: Contact support"; }
	if (getBytesInRaw()[0] & 0x01000000) { text << "\tmessage: Reserved"; }
	if (getBytesInRaw()[0] & 0x10000000) { text << "\tmessage: Reserved"; }

	// Error register 2
	if (getBytesInRaw()[2] & 0x00000001) { text << "\tmessage: Contact support"; }
	if (getBytesInRaw()[2] & 0x00000010) { text << "\tmessage: Contact support"; }
	if (getBytesInRaw()[2] & 0x00000100) { text << "\tmessage: Contact support"; }
	if (getBytesInRaw()[2] & 0x00001000) { text << "\tmessage: Contact support"; }
	if (getBytesInRaw()[2] & 0x00010000) { text << "\tmessage: Incorrect configuration data, load correct configuration values"; }
	if (getBytesInRaw()[2] & 0x00100000) { text << "\tmessage: Configuration contains incorrect parameters, load correct configuration values"; }
	if (getBytesInRaw()[2] & 0x01000000) { text << "\tmessage: Data processing timeout, decrease scan resolutiuon or scan frecuency"; }
	if (getBytesInRaw()[2] & 0x10000000) { text << "\tmessage: Contact support"; }
	if (getBytesInRaw()[2] & 0x00000001) { text << "\tmessage: Reserved"; }
	if (getBytesInRaw()[2] & 0x00000010) { text << "\tmessage: Reserved"; }
	if (getBytesInRaw()[2] & 0x00000100) { text << "\tmessage: Reserved"; }
	if (getBytesInRaw()[2] & 0x00001000) { text << "\tmessage: Reserved"; }
	if (getBytesInRaw()[2] & 0x00010000) { text << "\tmessage: Reserved"; }
	if (getBytesInRaw()[2] & 0x00100000) { text << "\tmessage: Reserved"; }
	if (getBytesInRaw()[2] & 0x01000000) { text << "\tmessage: Reserved"; }
	if (getBytesInRaw()[2] & 0x10000000) { text << "\tmessage: Reserved"; }

	// Warning register 1
	if (getBytesInRaw()[5] & 0x00000001) { text << "\tmessage: Internal communication error"; }
	if (getBytesInRaw()[5] & 0x00000010) { text << "\tmessage: Internal warning"; }
	if (getBytesInRaw()[5] & 0x00000100) { text << "\tmessage: Internal warning"; }
	if (getBytesInRaw()[5] & 0x00001000) { text << "\tmessage: Warning temperature very low"; }
	if (getBytesInRaw()[5] & 0x00010000) { text << "\tmessage: Warning temperature very high"; }
	if (getBytesInRaw()[5] & 0x00100000) { text << "\tmessage: Internal warning"; }
	if (getBytesInRaw()[5] & 0x01000000) { text << "\tmessage: Internal warning"; }
	if (getBytesInRaw()[5] & 0x10000000) { text << "\tmessage: Synchronization error, check synchronization and scan frecuency"; }
	if (getBytesInRaw()[4] & 0x00000001) { text << "\tmessage: Reserved"; }
	if (getBytesInRaw()[4] & 0x00000010) { text << "\tmessage: Reserved"; }
	if (getBytesInRaw()[4] & 0x00000100) { text << "\tmessage: Reserved"; }
	if (getBytesInRaw()[4] & 0x00001000) { text << "\tmessage: Reserved"; }
	if (getBytesInRaw()[4] & 0x00010000) { text << "\tmessage: Reserved"; }
	if (getBytesInRaw()[4] & 0x00100000) { text << "\tmessage: Reserved"; }
	if (getBytesInRaw()[4] & 0x01000000) { text << "\tmessage: Reserved"; }
	if (getBytesInRaw()[4] & 0x10000000) { text << "\tmessage: Reserved"; }

	// Warning register 2
	if (getBytesInRaw()[7] & 0x00000001) { text << "\tmessage: Reserved"; }
	if (getBytesInRaw()[7] & 0x00000010) { text << "\tmessage: Ethernet Interface blocked, check Ethernet connection"; }
	if (getBytesInRaw()[7] & 0x00001000) { text << "\tmessage: Contact support"; }
	if (getBytesInRaw()[7] & 0x00010000) { text << "\tmessage: Error receiving Ethernet data, check Ethernet conection/data"; }
	if (getBytesInRaw()[7] & 0x00100000) { text << "\tmessage: Incorrect or forbidden command received, check command"; }
	if (getBytesInRaw()[7] & 0x01000000) { text << "\tmessage: Memory access failure, restart LD-MRS, contact support"; }
	if (getBytesInRaw()[7] & 0x10000000) { text << "\tmessage: Reserved"; }
	if (getBytesInRaw()[6] & 0x00000001) { text << "\tmessage: Reserved"; }
	if (getBytesInRaw()[6] & 0x00000010) { text << "\tmessage: Reserved"; }
	if (getBytesInRaw()[6] & 0x00000100) { text << "\tmessage: Reserved"; }
	if (getBytesInRaw()[6] & 0x00001000) { text << "\tmessage: Reserved"; }
	if (getBytesInRaw()[6] & 0x00010000) { text << "\tmessage: Reserved"; }
	if (getBytesInRaw()[6] & 0x00100000) { text << "\tmessage: Reserved"; }
	if (getBytesInRaw()[6] & 0x01000000) { text << "\tmessage: Reserved"; }
	if (getBytesInRaw()[6] & 0x10000000) { text << "\tmessage: Reserved"; }
	return text.str();
}
