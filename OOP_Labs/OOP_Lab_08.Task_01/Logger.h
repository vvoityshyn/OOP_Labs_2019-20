#pragma once

#include <iostream>

using namespace std;

class Logger
{
private:
	Logger();
	~Logger();

public:

	static Logger* Instance();

	void Write(const char* message);
	void WriteLine(const char* message);
};

