#include "hdr/DateTime.h"
#include "boost/date_time/posix_time/posix_time.hpp"
#include <iomanip>		// para formateo de cout
using namespace std;	// para formateo de cout
namespace pt = boost::posix_time;

DateTime* DateTime::instance = 0;

DateTime* DateTime::getInstance() {
   if (!instance)
	   instance = new DateTime();

   return instance;
}

std::string DateTime::getCurrentDate (std::string separator) {
	pt::ptime now = pt::second_clock::local_time();
	std::stringstream ss;
	ss << now.date().year()
		<< separator
		<< setw(2) << setfill('0') << static_cast<int>(now.date().month())
		<< separator
		<< setw(2) << setfill('0') << now.date().day();

	return ss.str();
}

std::string DateTime::getCurrentTime (std::string separator) {
	pt::ptime now = pt::second_clock::local_time();
	std::stringstream ss;
	ss << setw(2) << setfill('0') << now.time_of_day().hours()
	   << separator
	   << setw(2) << setfill('0') << now.time_of_day().minutes()
	   << separator
	   << setw(2) << setfill('0') << now.time_of_day().seconds();
	return ss.str();
}
