#include "DepositInterest.h"

const int DepositInterest::GetNumberOfWholeYears(const Date& date1, const Date& date2) const
{
	int year;
	int month;
	int day;

	Date::Diff(date1, date2, &year, &month, &day);

	return year;
}