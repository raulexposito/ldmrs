#include "hdr/FileClient.h"
#include "../config/hdr/Configuration.h"
#include "../header/factory/hdr/HeaderFactory.h"

#define HEADER_SIZE 24
#define CHARS_PER_BYTE 2

FileClient* FileClient::instance = 0;

FileClient* FileClient::getInstance() {
   if (!instance)
	   instance = new FileClient();

   return instance;
}

FileClient::FileClient () {
	ifs.open(Configuration::getInstance()->getPath(), ifstream::in);
}

Message * FileClient::receive () {

	char * fileReadedBytes = new char[HEADER_SIZE * CHARS_PER_BYTE + 1];
	ifs.get(fileReadedBytes, HEADER_SIZE * CHARS_PER_BYTE + 1);
	cout << fileReadedBytes;


	return 0;

	//	Header * header = HeaderFactory::getInstance()->generateHeader(receivedHeaderBytes);
}
