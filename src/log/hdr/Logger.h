#ifndef LOGGER_H_
#define LOGGER_H_

#include <string>
#include <fstream>
#include <iostream>

using std::ostream;
using std::ofstream;
using std::cout;

/**
 * Clase destinada al guardado de logs
 */
class Logger {

	public:

		static Logger* getInstance();

		void log (std::string message);

	private:

		Logger();
		void createLogFile(bool create);
		void flushLogFile();
		std::string generateFilenameLog();

		static Logger* instance;
		bool logOnFile;
		bool logOnConsole;
		int logFileBuffer;
		int logFileBufferCounter;
		std::string filename;
		ofstream ofs;
};


#endif /* LOGGER_H_ */
