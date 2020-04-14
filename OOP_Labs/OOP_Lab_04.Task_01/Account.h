#pragma once

#include <iostream>

using namespace std;

class Account
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
public:
	Account(const char* identifier, const char* ownerName, const char* ownerAddress, const double amount);
	~Account();

	const char* GetIdentifier() const;
	const char* GetOwner() const;
	const char* GetOwnerAddress() const;

	const double GetAmount() const;

	void IncAmount(const double amount);
	void DecAmount(const double amount);

	friend ostream & operator<<(ostream &out, const Account &v);
};

