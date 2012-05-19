#ifndef NETWORKCLIENT_H
#define NETWORKCLIENT_H

#include <stdint.h> 	// para 'uint8_t'
#include "../../message/hdr/Message.h"


class NetworkClient {

	public:
		static NetworkClient* getInstance();

		void receive (int amountBytes);

		void send (Message * message);

	private:

		NetworkClient();
		NetworkClient(NetworkClient const&){};
		static NetworkClient* instance;
		int serverSocket;
};

#endif // NETWORKCLIENT_H
