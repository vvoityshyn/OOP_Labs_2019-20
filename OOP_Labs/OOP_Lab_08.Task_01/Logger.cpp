#include "Logger.h"

Logger::Logger()
{
	cout << "Logger::Logger()" << endl;
}

Logger::~Logger()
{
	cout << "Logger::~Logger()" << endl;
}

Logger* Logger::Instance()
{
	cout << "Logger::Instance()" << endl;
	static Logger instance;
	return &instance;
}

void Logger::Write(const char* message)
{
	cout << message;
}

void Logger::WriteLine(const char* message)
{
	cout << message << endl;
}
