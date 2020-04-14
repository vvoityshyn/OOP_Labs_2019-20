#pragma once
#include "Account.h"
#include "Date.h"

class DepositAccount :	public Account
{
private:
	double rate;
	Date creationDate;
	const int N = 1;
protected:
	// date2 - date1
	const int GetNumberOfWholeYears(const Date &date1, const Date &date2) const;
public:
	DepositAccount(
		const char* identifier, 
		const char* ownerName, 
		const char* ownerAddress, 
		const double amount,
		const double rate,
		const Date &creationDate);
	
	~DepositAccount();

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
	const double GetAmount(const Date &date) const;
};
