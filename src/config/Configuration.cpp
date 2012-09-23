#include "hdr/Configuration.h"

#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/ini_parser.hpp>

#include <iostream>		// para 'cout'

#define CONFIG_FILE "config.ini"
#define CONFIG_PARAM_SOURCE "source"
#define CONFIG_PARAM_TCPIP_IP "TCPIP.ip"
#define CONFIG_PARAM_TCPIP_PORT "TCPIP.port"
#define CONFIG_PARAM_FILE_PATH "FILE.path"
#define CONFIG_PARAM_FILE_MILISECONDS_BETWEEN_MESSAGES "FILE.milisecondsBetweenMessages"
#define CONFIG_PARAM_LOG_LOG_ON_CONSOLE "LOG.logOnConsole"
#define CONFIG_PARAM_LOG_LOG_ON_FILE "LOG.logOnFile"
#define CONFIG_PARAM_LOG_LOG_FILE_BUFFER "LOG.logFileBuffer"
#define CONFIG_PARAM_RECORD_RECORD_MEASUREMENTS "RECORD.recordMeasurements"
#define CONFIG_PARAM_RECORD_RECORD_MEASUREMENTS_BUFFER "RECORD.recordMeasurementsBuffer"
#define CONFIG_PARAM_POINTCLOUD_SHOW_POINTCLOUD "POINTCLOUD.showPointCloud"
#define CONFIG_PARAM_POINTCLOUD_RECORD_POINTCLOUD "POINTCLOUD.recordPointCloud"


using namespace std;

std::string getParameter(std::string parameter);


Configuration* Configuration::instance = 0;

Configuration* Configuration::getInstance() {
   if (!instance)
	   instance = new Configuration();

   return instance;
}

void Configuration::print () {
	boost::property_tree::ptree pt;
	boost::property_tree::ini_parser::read_ini(CONFIG_FILE, pt);
	cout << pt.get<std::string>(CONFIG_PARAM_SOURCE) << std::endl;
	cout << pt.get<std::string>(CONFIG_PARAM_TCPIP_IP) << std::endl;
	cout << pt.get<std::string>(CONFIG_PARAM_TCPIP_PORT) << std::endl;
	cout << pt.get<std::string>(CONFIG_PARAM_FILE_PATH) << std::endl;
}

SourceEnum Configuration::getSource() {
	std::string source = getParameter(CONFIG_PARAM_SOURCE);
	if (source.compare("FILE") == 0) return SOURCE_FILE;
	return SOURCE_TCPIP;
}

std::string Configuration::getIp() {
	return getParameter(CONFIG_PARAM_TCPIP_IP);
}

int Configuration::getPort() {
	return atoi(getParameter(CONFIG_PARAM_TCPIP_PORT).c_str());
}

const char * Configuration::getPath() {
	return getParameter(CONFIG_PARAM_FILE_PATH).c_str();
}

bool Configuration::isLogOnConsole() {
	return getParameter(CONFIG_PARAM_LOG_LOG_ON_CONSOLE) == "true";
}

bool Configuration::isLogOnFile() {
	return getParameter(CONFIG_PARAM_LOG_LOG_ON_FILE) == "true";
}

int Configuration::getLogFileBuffer() {
	return atoi(getParameter(CONFIG_PARAM_LOG_LOG_FILE_BUFFER).c_str());
}

bool Configuration::isRecordMeasurements() {
	return getParameter(CONFIG_PARAM_RECORD_RECORD_MEASUREMENTS) == "true";
}

int Configuration::getRecordMeasurementsBuffer() {
	return atoi(getParameter(CONFIG_PARAM_RECORD_RECORD_MEASUREMENTS_BUFFER).c_str());
}

float Configuration::getMilisecondsBetweenMessages() {
	return (atoi(getParameter(CONFIG_PARAM_FILE_MILISECONDS_BETWEEN_MESSAGES).c_str())) / 1000;
}

bool Configuration::isShowPointCloud() {
	return getParameter(CONFIG_PARAM_POINTCLOUD_SHOW_POINTCLOUD) == "true";
}

bool Configuration::isRecordPointCloud() {
	return getParameter(CONFIG_PARAM_POINTCLOUD_RECORD_POINTCLOUD) == "true";
}

// http://stackoverflow.com/questions/6175502/how-to-parse-ini-file-with-boost
std::string getParameter(std::string parameter) {
	boost::property_tree::ptree pt;
	boost::property_tree::ini_parser::read_ini(CONFIG_FILE, pt);
	return pt.get<std::string>(parameter);
}
