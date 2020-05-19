#pragma once

#include <string>
#include <iostream>

using namespace std;

class AppConfig
{
private:
	string dbConection;
	string logFile;
	string localization;

	static AppConfig* instance;

	AppConfig();

public:

	static AppConfig* Instance();
	
	~AppConfig();

	const string GetDBConnection() const;
	const string GetLogFile() const;
	const string GetLocalization() const;
};

