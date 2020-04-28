#include "BankAccount.h"
#include "string.h"


BankAccount::BankAccount(const char * identifier, const char * ownerName, const char * ownerAddress, const double amount)
{
	printf("BankAccount::BankAccount(const char * %s, const char * %s, const char * %s, const double %f)\n", identifier, ownerName, ownerAddress, amount);

	if (amount < 0)
	{
		throw "Incorrect amount";
	}

	this->identifier = CopyText(identifier);
	this->ownerName = CopyText(ownerName);
	this->ownerAddress = CopyText(ownerAddress);
	this->amount = amount;
}

BankAccount::~BankAccount()
{
	delete[] this->identifier;
	delete[] this->ownerName;
	delete[] this->ownerAddress;

	cout << "BankAccount::~BankAccount()" << endl;
}

char* BankAccount::CopyText(const char* source)
{
	int bufferLength = strlen(source) + 1;
	char* destination = new char[bufferLength];
	strcpy_s(destination, bufferLength, source);
	return destination;
}

const char * BankAccount::GetIdentifier() const
{
	return this->identifier;
}

const char * BankAccount::GetOwnerName() const
{
	return this->ownerName;
}

const char * BankAccount::GetOwnerAddress() const
{
	return this->ownerAddress;
}

const double BankAccount::GetAmount() const
{
	printf("BankAccount::GetAmount()\n");
	return this->amount;
}

void BankAccount::TransferFunds(const double amount)
{
	this->amount += amount;
}
