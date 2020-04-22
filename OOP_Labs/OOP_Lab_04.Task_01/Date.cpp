#include "Date.h"


bool Date::IsValidDate(int year, int month, int day)
{
	// TODO: implement date validation
	return true;
}

Date::Date(int year, int month, int day)
{
	printf("Date::Date(int %d, int %d, int %d)\n", year, month, day);

	if (!this->IsValidDate(year, month, day))
	{
		throw "Incorrect date";
	}

	this->year = year;
	this->month = month;
	this->day = day;
}

Date::Date(const Date & date)
{
	cout << "Date::Date(const Date & date)" << endl;
	this->year = date.year;
	this->month = date.month;
	this->day = date.day;
}


Date::~Date()
{
	cout << "Date::~Date()" << endl;
}

int Date::GetYear() const
{
	return this->year;
}

int Date::GetMonth() const
{
	return this->month;
}

int Date::GetDay() const
{
	return this->day;
}

void Date::Diff(const Date & from, const Date & to, int * years, int * months, int * days)
{
	static int increment[12] = { 1, -2, 1, 0, 1, 1, 0, 1, 0, 1, 0, 1 };

	int daysInc = 0;
	if (to.GetDay() - from.GetDay() < 0)
	{
		int month = to.GetMonth() - 2; // -1 from zero, -1 previous month.
		if (month < 0)
			month = 11; // Previous month is December.
		daysInc = increment[month];
		if ((month == 1) && (to.GetYear() % 4 == 0))
			daysInc++; // Increment days for leap year.
	}

	int total1 = from.GetYear() * 360 + from.GetMonth() * 30 + from.GetDay();
	int total2 = to.GetYear() * 360 + to.GetMonth() * 30 + to.GetDay();
	int diff = total2 - total1;

	int _years = diff / 360;
	int _months = (diff - _years * 360) / 30;
	int _days = diff - _years * 360 - _months * 30 + daysInc;

	// Extra calculation when we can pass one month instead of 30 days.
	if (from.GetDay() == 1 && to.GetDay() == 31) {
		_months--;
		_days = 30;
	}

	*years = _years;
	*months = _months;
	*days = _days;
}
