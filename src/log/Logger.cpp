#include "hdr/Logger.h"
#include "../config/hdr/Configuration.h"
#include "../util/hdr/DateTime.h"

#define GENERIC_LOG_FILE_NAME "ldmrs.log"

#define NO_SEPARATOR ""

#define DATE_SEPARATOR "/"

#define TIME_SEPARATOR ":"

Logger* Logger::instance = 0;

Logger* Logger::getInstance() {
   if (!instance) {
	   instance = new Logger();
   }

   return instance;
}

Logger::Logger() {
	logOnConsole=Configuration::getInstance()->isLogOnConsole();
	logOnFile=Configuration::getInstance()->isLogOnFile();
	logFileBuffer=Configuration::getInstance()->getLogFileBuffer();
	logFileBufferCounter=0;
	createLogFile(logOnFile);
}

void Logger::log(std::string message) {

	std::string logMessage =
			"[" +
			DateTime::getInstance()->getCurrentDate(DATE_SEPARATOR) +
			" " +
			DateTime::getInstance()->getCurrentTime(TIME_SEPARATOR) +
			"] " +
			message;

    if (logOnConsole) {
    	cout << logMessage << "\n";
    }

    if (logOnFile) {
    	ofs << logMessage << "\n";
    	flushLogFile();
    }
}

void Logger::createLogFile(bool create) {
	if (create) {
		filename=generateFilenameLog();
		ofs.open(filename.c_str());
	}
}

void Logger::flushLogFile() {
    logFileBufferCounter ++;
    if (logFileBufferCounter >= logFileBuffer) {
    	logFileBufferCounter = 0;
    	ofs.flush();
    }
}

std::string Logger::generateFilenameLog () {
	std::string file =
			DateTime::getInstance()->getCurrentDate(NO_SEPARATOR) +
			"-" +
			DateTime::getInstance()->getCurrentTime(NO_SEPARATOR) +
			"_" +
			GENERIC_LOG_FILE_NAME;

	return file;
}
