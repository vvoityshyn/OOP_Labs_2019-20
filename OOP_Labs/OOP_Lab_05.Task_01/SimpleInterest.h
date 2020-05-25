#pragma once
#include "DepositInterest.h"

class SimpleInterest : public DepositInterest
{
public:
	double CalculateAmount(double startAmount, double rate, Date creationDate, Date targetDate);
};

