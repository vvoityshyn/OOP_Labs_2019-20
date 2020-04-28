#include "DepositAccount.h"

const int DepositAccount::GetNumberOfWholeYears(const Date & date1, const Date & date2) const
{
	int year;
	int month;
	int day;

	Date::Diff(date1, date2, &year, &month, &day);

	return year;
}

DepositAccount::DepositAccount(
		const char * identifier, 
		const char * ownerName, 
		const char * ownerAddress, 
		const double amount, 
		const double rate, 
		const Date & creationDate) : BankAccount(identifier, ownerName, ownerAddress, amount)
{
	printf("DepositAccount::DepositAccount(const char * %s, const char * %s, const char * %s, const double %f, const double %f, const Date & creationDate)\n", identifier, ownerName, ownerAddress, amount, rate);

	if (!(0.0 < rate && rate <= 1.0))
	{
		throw "Incorrect interest rate";
	}

	this->rate = rate;

	this->creationDate = new Date(creationDate);
}

DepositAccount::~DepositAccount()
{
	delete creationDate;
	cout << "DepositAccount::~DepositAccount()" << endl;
}

const double DepositAccount::GetAmount() const
{
	printf("DepositAccount::GetAmount()\n");
	return BankAccount::GetAmount();
}

const double DepositAccount::GetAmount(const Date &date) const
{
	double p0 = this->GetAmount();
	double t = this->GetNumberOfWholeYears(*(this->creationDate), date);
	double r = this->rate;
	double n = this->N;
	double p = p0 * pow(1 + r / n, n * t);
	return p;
}

void DepositAccount::PutFunds(const double amount)
{
	printf("DepositAccount::PutFunds(const double %lf)\n", amount);

	if (amount < 0)
	{
		throw "Incorrect amount";
	}
	this->TransferFunds(amount);
}

void DepositAccount::WithdrawFunds(const double amount)
{
	printf("DepositAccount::WithdrawFunds(const double %lf)\n", amount);

	throw "WithdrawFunds() cannot be applied to a deposit account";
}

//ostream & operator<<(ostream & out, const DepositAccount & account)
//{
//	out
//		<< "Deposit bank account: " << endl
//		<< "\t" << "identifier:" << "\t" << account.GetIdentifier() << endl
//		<< "\t" << "owner name:" << "\t" << account.GetOwnerName() << endl
//		<< "\t" << "owner address:" << "\t" << account.GetOwnerAddress() << endl
//		<< "\t" << "amount:" << "\t" << account.GetAmount() << endl
//		<< "\t" << "interest rate:" << "\t" << account.rate << endl;
//
//	return out;
//}