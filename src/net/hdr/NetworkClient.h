#ifndef NETWORKCLIENT_H
#define NETWORKCLIENT_H

#include <stdint.h> 	// para 'uint8_t'
#include "../../message/hdr/Message.h"


class NetworkClient {

	public:
		static NetworkClient* getInstance();

		Message * receive ();

		void send (Message * message);

	private:

		NetworkClient();
		NetworkClient(NetworkClient const&){};
		uint8_t * receiveBody(int bodySize);
		static NetworkClient* instance;
		int serverSocket;
};

#endif // NETWORKCLIENT_H
