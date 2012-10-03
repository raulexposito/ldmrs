#ifndef DATETIME_H_
#define DATETIME_H_

#include <string>

class DateTime {

	public:

		static DateTime* getInstance();

		std::string getCurrentDate (std::string separator);

		std::string getCurrentTime (std::string separator);

	private:

		DateTime(){};

		DateTime(DateTime const&){};

		static DateTime* instance;
};

#endif /* DATETIME_H_ */
