#include "hdr/Recorder.h"
#include "../config/hdr/Configuration.h"
#include "../util/hdr/DateTime.h"

#include "../util/hdr/BytesConverter.h"

#include <sstream>
#include <iostream>		// para 'cout'
#include <iomanip>		// para formateo de cout
using namespace std;	// para formateo de cout

#define GENERIC_LOG_FILE_NAME "record.log"

#define NO_SEPARATOR ""

#define DATE_SEPARATOR "/"

#define TIME_SEPARATOR ":"

Recorder* Recorder::instance = 0;

Recorder* Recorder::getInstance() {
   if (!instance) {
	   instance = new Recorder();
   }
   return instance;
}

Recorder::Recorder() {
	recordMeasurements=Configuration::getInstance()->isRecordMeasurements();
	recordMeasurementsBuffer=Configuration::getInstance()->getRecordMeasurementsBuffer();
	recordMeasurementsBufferCounter=0;
	createRecordFile(recordMeasurements);
}

std::string composeTrace (Message * message) {

	std::stringstream messageBytes;
	int i;

	for (i = 0; i < message->getAmountBytes(); i++) {
		messageBytes << setw(2) << setfill('0') << hex << uppercase << (int) message->getBytesInRaw()[i];
	}

	return messageBytes.str();
}

void Recorder::record(Message * message) {
    if (recordMeasurements) {
    	ofs << composeTrace(message) << endl;
    	flushRecordFile();
    }
}

void Recorder::createRecordFile(bool create) {
	if (create) {
		filename=generateFilenameRecord();
		ofs.open(filename.c_str());
	}
}

void Recorder::flushRecordFile() {
	recordMeasurementsBufferCounter ++;
    if (recordMeasurementsBufferCounter >= recordMeasurementsBuffer) {
    	recordMeasurementsBufferCounter = 0;
    	ofs.flush();
    }
}

std::string Recorder::generateFilenameRecord () {
	std::string file =
			DateTime::getInstance()->getCurrentDate(NO_SEPARATOR) +
			"-" +
			DateTime::getInstance()->getCurrentTime(NO_SEPARATOR) +
			"_" +
			GENERIC_LOG_FILE_NAME;

	return file;
}
