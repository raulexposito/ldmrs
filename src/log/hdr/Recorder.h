#ifndef RECORDER_H_
#define RECORDER_H_

#include <string>
#include <fstream>
#include <iostream>
#include <sstream>

#include "../../message/hdr/Message.h"

using std::ostream;
using std::ofstream;
using std::cout;

/**
 * Clase destinada al guardado de mensajes recibidos por el laser
 */
class Recorder {

	public:

		static Recorder* getInstance();

		void record (Message * message);

	private:

		Recorder();

		void createRecordFile(bool create);

		std::string generateFilenameRecord();

		void flushRecordFile();

		static Recorder* instance;

		bool recordMeasurements;

		int recordMeasurementsBuffer;

		int recordMeasurementsBufferCounter;

		std::string filename;

		std::stringstream recordBuffer;

		ofstream ofs;
};

#endif /* RECORDER_H_ */
