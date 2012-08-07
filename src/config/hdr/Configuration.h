#ifndef CONFIGURATION_H_
#define CONFIGURATION_H_

#include "../enum/SourceEnum.h"
#include <string>

/**
 * Clase basica con todos los elementos que requieren los encabezados del protocolo LD-MRS
 */
class Configuration {

	public:

		static Configuration* getInstance();

		void print ();

		SourceEnum getSource();

		std::string getIp();

		int getPort();

		std::string getPath();

		bool isLogOnConsole();

		bool isLogOnFile();

		int getLogFileBuffer();

		bool isRecordMeasurements();

		int getRecordMeasurementsBuffer();

	private:

		Configuration(){};
		static Configuration* instance;
};


#endif /* CONFIGURATION_H_ */
