#include "AppConfig.h"

AppConfig* AppConfig::instance = nullptr;

AppConfig::AppConfig()
{
	cout << "AppConfig::AppConfig()" << endl;
}

AppConfig* AppConfig::Instance()
{
	if (nullptr == AppConfig::instance)
	{
		cout << "AppConfig::Instance()" << endl;
		AppConfig::instance = new AppConfig();
	}
	return AppConfig::instance;
}

AppConfig::~AppConfig()
{
	AppConfig::instance = nullptr;
	cout << "AppConfig::~AppConfig()" << endl;
}

const string AppConfig::GetDBConnection() const
{
	return this->dbConection;
}

const string AppConfig::GetLogFile() const
{
	return this->logFile;
}

const string AppConfig::GetLocalization() const
{
	return this->localization;
}
