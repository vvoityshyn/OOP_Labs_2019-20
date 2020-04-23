#pragma once

#include "BankAccount.h"

// Поточний рахунок
class CurrentAccount : public BankAccount
{
private:

public:
	CurrentAccount(const char* identifier, const char* ownerName, const char* ownerAddress, const double amount);
	~CurrentAccount();

	virtual void IncAmount(const double amount);
	virtual void DecAmount(const double amount);

	friend ostream & operator<<(ostream &out, const CurrentAccount &v);
};

