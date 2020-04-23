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
