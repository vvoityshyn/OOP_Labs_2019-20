#pragma once

#include <iostream>

using namespace std;

class Date
{
private:
	int year;	// starts from 0
	int month; // starts from 1
	int day;	// starts from 1

	bool IsValidDate(int year, int month, int day);
public:
	Date(int year, int month, int day);
	Date(const Date & date);
	~Date();

	int GetYear() const;
	int GetMonth() const;
	int GetDay() const;

	/* 
		Date difference: from - to
		Outcome: years, months, days
	*/
	static void Diff(const Date & from, const Date & to, int * years, int * months, int * days);
};

