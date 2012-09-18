#ifndef CONNECTOR_H_
#define CONNECTOR_H_

#include "../../message/hdr/Message.h"

/**
 * Clase basica con todos los elementos que requieren los encabezados del protocolo LD-MRS
 */
class Connector {

	public:

		void sendMessage(Message * message);

		Message * receiveMessage();
};


#endif /* CONNECTOR_H_ */
