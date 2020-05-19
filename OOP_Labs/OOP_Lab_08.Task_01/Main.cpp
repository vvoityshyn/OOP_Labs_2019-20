#include <iostream>
#include "AppConfig.h"
#include "Logger.h"

using namespace std;

void TestAppConfig();
void TestLogger();

int main()
{
	cout << "OOP_Lab_08.Task_01" << endl;

	//TestAppConfig();	
	TestLogger();

	system("pause");
	return 0;
}

void TestAppConfig()
{
	AppConfig* config1 = AppConfig::Instance();
	AppConfig* config2 = AppConfig::Instance();
	AppConfig* config3 = AppConfig::Instance();

	// Instance cannot be created via direct calling the constructor
	//AppConfig* config4 = new AppConfig();
	//AppConfig config5;

	AppConfig* config = AppConfig::Instance();
	delete config;

	AppConfig* config4 = AppConfig::Instance();
}

void TestLogger()
{
	Logger* log1 = Logger::Instance();
	Logger* log2 = Logger::Instance();
	Logger* log3 = Logger::Instance();

	log1->WriteLine("This is Logger!!!");	
}