#include "CurrentAccount.h"

CurrentAccount::CurrentAccount(const char * identifier, const char * ownerName, const char * ownerAddress, const double amount)
	: BankAccount(identifier, ownerName, ownerAddress, amount)
{
	printf("CurrentAccount::CurrentAccount(const char * %s, const char * %s, const char * %s, const double %f)\n", identifier, ownerName, ownerAddress, amount);

}

CurrentAccount::~CurrentAccount()
{
	cout << "CurrentAccount::~CurrentAccount()" << endl;
}

void CurrentAccount::PutFunds(const double amount)
{
	printf("CurrentAccount::PutFunds(const double %lf)\n", amount);

	if (amount < 0)
	{
		throw "Incorrect amount";
	}
	this->TransferFunds(amount);
}

void CurrentAccount::WithdrawFunds(const double amount)
{
	printf("CurrentAccount::WithdrawFunds(const double %lf)\n", amount);

	if (amount < 0)
	{
		throw "Incorrect amount";
	}
	if (this->GetAmount() - amount < 0)
	{
		throw "Not enough money";
	}
	this->TransferFunds((-1) * amount);
}

//ostream & operator<<(ostream & out, const CurrentAccount & account)
//{
//	out
//		<< "Current account: " << endl
//		<< "\t" << "identifier:" << "\t" << account.GetIdentifier() << endl
//		<< "\t" << "owner name:" << "\t" << account.GetOwnerName() << endl
//		<< "\t" << "owner address:" << "\t" << account.GetOwnerAddress() << endl
//		<< "\t" << "amount:" << "\t" << account.GetAmount() << endl;
//
//	return out;
//}
