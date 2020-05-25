#pragma once
#include "DepositInterest.h"

class CompoundInterest :	public DepositInterest
{
private:
	int n;

public:
	CompoundInterest(int n);
	/*
		Validation rule: creationDate <= date
		Compound interest:

		P = P0 * (1 + r / n)^(n * t)

			P0 is the original principal amount
			P is the new principal amount
			r is the nominal annual interest rate
			n is the compounding frequency (in our case n = 1)
			t number of whole years spent from creationDate

		https://en.wikipedia.org/wiki/Compound_interest
	*/
	double CalculateAmount(double startAmount, double rate, Date creationDate, Date targetDate);
};

