#pragma once

#include <iostream>

using namespace std;

class BankAccount
{
private:
	// Account identifier (IBAN)
	char* identifier;
	// Owner's full name
	char* ownerName;
	// Owner's address
	char* ownerAddress;
	// Amount
	double amount;

	char* CopyText(const char* source);

protected:
	void TransferFunds(const double amount);

public:
	BankAccount(const char* identifier, const char* ownerName, const char* ownerAddress, const double amount);
	virtual ~BankAccount();

	const char* GetIdentifier() const;
	const char* GetOwnerName() const;
	const char* GetOwnerAddress() const;

	const double GetAmount() const;

	virtual void PutFunds(const double amount) = 0;
	virtual void WithdrawFunds(const double amount) = 0;
};

