#ifndef NETWORKCLIENT_H
#define NETWORKCLIENT_H

#include <stdint.h> 	// para 'uint8_t'
#include "../../message/hdr/Message.h"

/**
 * Clase encargada de enviar y recibir mensajes al y desde el laser
 */
class NetworkClient {

	public:

		static NetworkClient* getInstance();

		Message * receive ();

		void send (Message * message);

		void resetConnection ();

	private:

		NetworkClient();

		NetworkClient (NetworkClient const&){};

		uint8_t * receiveBody (int bodySize);

		Header * getHeader ();

		Body * getBody (Header * header);

		bool isMagicWord (uint8_t * magicWord);

		void log (bool sent, Message * message);

		static NetworkClient* instance;

		int serverSocket;
};

#endif // NETWORKCLIENT_H
