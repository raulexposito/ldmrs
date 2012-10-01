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

	std::string byte0 = getBinaryRepresentation(getBytesInRaw()[0]);
	std::string byte1 = getBinaryRepresentation(getBytesInRaw()[1]);
	std::string byte2 = getBinaryRepresentation(getBytesInRaw()[2]);
	std::string byte3 = getBinaryRepresentation(getBytesInRaw()[3]);
	std::string byte4 = getBinaryRepresentation(getBytesInRaw()[4]);
	std::string byte5 = getBinaryRepresentation(getBytesInRaw()[5]);
	std::string byte6 = getBinaryRepresentation(getBytesInRaw()[6]);
	std::string byte7 = getBinaryRepresentation(getBytesInRaw()[7]);

    // Error register 1
	if (byte0.at(7) == '1') { text << "message: Contact support "; }
	if (byte0.at(6) == '1') { text << "message: Contact support "; }
	if (byte0.at(5) == '1') { text << "message: Scan buffered transmitted incompletely, decrease scan resolution/frecuency/range; contact support "; }
	if (byte0.at(4) == '1') { text << "message: Scan buffer overflow, decrease scan resolution/frecuency/range; contact support "; }
	if (byte0.at(3) == '1') { text << "message: Contact support "; }
	if (byte0.at(2) == '1') { text << "message: Reserved "; }
	if (byte0.at(1) == '1') { text << "message: Reserved "; }
	if (byte0.at(0) == '1') { text << "message: Reserved "; }
	if ((byte1.at(6) == '1') && (byte1.at(7) == '1')) { text << "message: APD Temperature Sensor defect, contact support";}
	else {
		if (byte1.at(7) == '1') { text << "message: ADP Under Temperature, provide heating "; }
		if (byte1.at(6) == '1') { text << "message: ADP Over Temperature, provide cooling "; }
	}
	if (byte1.at(5) == '1') { text << "message: Contact support "; }
	if (byte1.at(4) == '1') { text << "message: Contact support "; }
	if (byte1.at(3) == '1') { text << "message: Contact support "; }
	if (byte1.at(2) == '1') { text << "message: Contact support "; }
	if (byte1.at(1) == '1') { text << "message: Reserved "; }
	if (byte1.at(0) == '1') { text << "message: Reserved "; }

	// Error register 2
	if (byte2.at(7) == '1') { text << "message: Contact support "; }
	if (byte2.at(6) == '1') { text << "message: Contact support "; }
	if (byte2.at(5) == '1') { text << "message: Contact support "; }
	if (byte2.at(4) == '1') { text << "message: Contact support "; }
	if (byte2.at(3) == '1') { text << "message: Incorrect configuration data, load correct configuration values "; }
	if (byte2.at(2) == '1') { text << "message: Configuration contains incorrect parameters, load correct configuration values "; }
	if (byte2.at(1) == '1') { text << "message: Data processing timeout, decrease scan resolutiuon or scan frecuency "; }
	if (byte2.at(0) == '1') { text << "message: Contact support "; }
	if (byte3.at(7) == '1') { text << "message: Reserved "; }
	if (byte3.at(6) == '1') { text << "message: Reserved "; }
	if (byte3.at(5) == '1') { text << "message: Reserved "; }
	if (byte3.at(4) == '1') { text << "message: Reserved "; }
	if (byte3.at(3) == '1') { text << "message: Reserved "; }
	if (byte3.at(2) == '1') { text << "message: Reserved "; }
	if (byte3.at(1) == '1') { text << "message: Reserved "; }
	if (byte4.at(0) == '1') { text << "message: Reserved "; }

	// Warning register 1
	if (byte4.at(7) == '1') { text << "message: Internal communication error "; }
	if (byte4.at(6) == '1') { text << "message: Internal warning "; }
	if (byte4.at(5) == '1'){ text << "message: Internal warning "; }
	if (byte4.at(4) == '1') { text << "message: Warning temperature very low "; }
	if (byte4.at(3) == '1') { text << "message: Warning temperature very high "; }
	if (byte4.at(2) == '1') { text << "message: Internal warning "; }
	if (byte4.at(1) == '1') { text << "message: Internal warning "; }
	if (byte4.at(0) == '1') { text << "message: Synchronization error, check synchronization and scan frecuency "; }
	if (byte5.at(7) == '1') { text << "message: Reserved "; }
	if (byte5.at(6) == '1') { text << "message: Reserved "; }
	if (byte5.at(5) == '1') { text << "message: Reserved "; }
	if (byte5.at(4) == '1') { text << "message: Reserved "; }
	if (byte5.at(3) == '1') { text << "message: Reserved "; }
	if (byte5.at(2) == '1') { text << "message: Reserved "; }
	if (byte5.at(1) == '1') { text << "message: Reserved "; }
	if (byte5.at(0) == '1') { text << "message: Reserved "; }

	// Warning register 2
	if (byte6.at(7) == '1') { text << "message: Reserved "; }
	if (byte6.at(6) == '1') { text << "message: Ethernet Interface blocked, check Ethernet connection "; }
	if (byte6.at(5) == '1') { text << "message: Contact support "; }
	if (byte6.at(4) == '1') { text << "message: Error receiving Ethernet data, check Ethernet conection/data "; }
	if (byte6.at(3) == '1') { text << "message: Incorrect or forbidden command received, check command "; }
	if (byte6.at(2) == '1') { text << "message: Memory access failure, restart LD-MRS, contact support "; }
	if (byte6.at(1) == '1') { text << "message: Reserved "; }
	if (byte7.at(7) == '1') { text << "message: Reserved "; }
	if (byte7.at(6) == '1') { text << "message: Reserved "; }
	if (byte7.at(5) == '1') { text << "message: Reserved "; }
	if (byte7.at(4) == '1') { text << "message: Reserved "; }
	if (byte7.at(3) == '1') { text << "message: Reserved "; }
	if (byte7.at(2) == '1') { text << "message: Reserved "; }
	if (byte7.at(1) == '1') { text << "message: Reserved "; }
	if (byte7.at(0) == '1') { text << "message: Reserved "; }
	return text.str();
}

std::string ErrorAndWarningBody::getBinaryRepresentation (uint8_t value) {
    const int size=sizeof(value)*8;
    std::string res;
    std::stringstream message;
    bool s=0;
    for (int a=0;a<size;a++){
        bool bit=value>>(size-1);
        if (bit)
            s=1;
        if (s) {
            res.push_back(bit+'0');
        } else {
        	res.push_back('0');
        }
        value<<=1;
    }

    return res;
}
