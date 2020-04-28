#include "LoanAccount.h"



LoanAccount::LoanAccount(const char* identifier, const char* ownerName, const char* ownerAddress, const double amount)
	: BankAccount(identifier, ownerName, ownerAddress, amount)
{
	printf("LoanAccount::LoanAccount(const char * %s, const char * %s, const char * %s, const double %f)\n", identifier, ownerName, ownerAddress, amount);
}


LoanAccount::~LoanAccount()
{
	cout << "LoanAccount::~LoanAccount()" << endl;
}

void LoanAccount::PutFunds(const double amount)
{
	printf("LoanAccount::PutFunds(const double %lf)\n", amount);

	if (amount < 0)
	{
		throw "Incorrect amount";
	}
	this->TransferFunds(amount);
}

void LoanAccount::WithdrawFunds(const double amount)
{
	printf("LoanAccount::WithdrawFunds(const double %lf)\n", amount);

	if (amount < 0)
	{
		throw "Incorrect amount";
	}
	this->TransferFunds((-1) * amount);
}