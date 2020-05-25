#pragma once
#include "Date.h"

class DepositInterest
{
protected:
	const int GetNumberOfWholeYears(const Date& date1, const Date& date2) const;
	
public:
	virtual double CalculateAmount(double startAmount, double rate, Date creationDate, Date targetDate) = 0;
};

