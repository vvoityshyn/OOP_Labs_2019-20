#include "DepositAccount.h"

const int DepositAccount::GetNumberOfWholeYears(const Date & date1, const Date & date2) const
{
	return 2;
}

DepositAccount::DepositAccount(
		const char * identifier, 
		const char * ownerName, 
		const char * ownerAddress, 
		const double amount, 
		const double rate, 
		const Date & creationDate) : Account(identifier, ownerName, ownerAddress, amount)
{
	printf("DepositAccount::DepositAccount(const char * %s, const char * %s, const char * %s, const double %f, const double %f, const Date & creationDate)\n", identifier, ownerName, ownerAddress, amount, rate);

	if (!(0.0 < rate && rate <= 1.0))
	{
		throw "Incorrect interest rate";
	}

	this->rate = rate;

	this->creationDate = creationDate;
}

DepositAccount::~DepositAccount()
{
	cout << "DepositAccount::~DepositAccount()" << endl;
}

const double DepositAccount::GetAmount(const Date &date) const
{
	double p0 = Account::GetAmount();
	double t = this->GetNumberOfWholeYears(this->creationDate, date);
	double r = this->rate;
	double n = this->N;
	double p = p0 * pow(1 + r / n, n * t);
	return p;
}
