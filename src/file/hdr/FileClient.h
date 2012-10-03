#ifndef FILECLIENT_H_
#define FILECLIENT_H_

#include "../../message/hdr/Message.h"
#include <iostream>
#include <fstream>

using std::ifstream;
using std::cout;

/**
 * Clase encargada de leer las grabaciones realizadas en fichero
 */
class FileClient {

	public:

		static FileClient* getInstance();

		Message * receive ();

	private:

		FileClient();

		FileClient(FileClient const&){};

		Header * generateHeader (const char * headerReadedBytes);

		Body * generateBody (const char * bodyReadedBytes, Header * header);

		void log (Message * message);

		static FileClient* instance;

		ifstream ifs;

		uint8_t convert(char value, bool first);
};


#endif /* FILECLIENT_H_ */
