#ifndef FILECLIENT_H_
#define FILECLIENT_H_

#include "../../message/hdr/Message.h"
#include <iostream>
#include <fstream>

using std::ifstream;
using std::cout;

class FileClient {

	public:
		static FileClient* getInstance();

		Message * receive ();

	private:

		FileClient();
		FileClient(FileClient const&){};
		Header * generateHeader (char * headerReadedBytes);
		Body * generateBody (char * bodyReadedBytes, Header * header);
		static FileClient* instance;
		ifstream ifs;

		uint8_t convert(char value, bool first);
};


#endif /* FILECLIENT_H_ */
