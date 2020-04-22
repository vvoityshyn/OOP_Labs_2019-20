#include "Account.h"
#include "string.h"

Account::Account(const char * identifier, const char * ownerName, const char * ownerAddress, const double amount)
{
	printf("Account::Account(const char * %s, const char * %s, const char * %s, const double %f)\n", identifier, ownerName, ownerAddress, amount);

	if (amount < 0)
	{
		throw "Incorrect amount";
	}

	this->identifier = CopyText(identifier);
	this->ownerName = CopyText(ownerName);
	this->ownerAddress = CopyText(ownerAddress);
	this->amount = amount;
}

Account::~Account()
{
	delete[] this->identifier;
	delete[] this->ownerName;
	delete[] this->ownerAddress;

	cout << "Account::~Account()" << endl;
}

const char * Account::GetIdentifier() const
{
	return this->identifier;
}

const char * Account::GetOwner() const
{
	return this->ownerName;
}

const char * Account::GetOwnerAddress() const
{
	return this->ownerAddress;
}

const double Account::GetAmount() const
{
	printf("Account::GetAmount()\n");
	return this->amount;
}

void Account::IncAmount(const double amount)
{
	printf("Account::IncAmount(const double %lf)\n", amount);

	if (amount < 0)
	{
		throw "Incorrect amount";
	}
	this->amount += amount;
}

void Account::DecAmount(const double amount)
{
	printf("Account::DecAmount(const double %lf)\n", amount);

	if (amount < 0)
	{
		throw "Incorrect amount";
	}
	if (this->amount - amount < 0)
	{
		throw "Not enough money";
	}
	this->amount -= amount;
}

char* Account::CopyText(const char* source)
{
	int bufferLength = strlen(source) + 1;
	char* destination = new char[bufferLength];
	strcpy_s(destination, bufferLength, source);
	return destination;
}

ostream & operator<<(ostream & out, const Account & account)
{
	out
		<< "Bank account: " << endl
		<< "\t" << "identifier:" << "\t" << account.identifier << endl
		<< "\t" << "owner name:" << "\t" << account.ownerName << endl
		<< "\t" << "owner address:" << "\t" << account.ownerAddress << endl
		<< "\t" << "amount:" << "\t" << account.amount << endl;

	return out;
}
