#pragma once

#include "BankAccount.h"

// Поточний рахунок
class CurrentAccount : public BankAccount
{
private:

protected:
	void Print(ostream & out) const;

public:
	CurrentAccount(const char* identifier, const char* ownerName, const char* ownerAddress, const double amount);
	~CurrentAccount();

	void PutFunds(const double amount);
	void WithdrawFunds(const double amount);	

	//friend ostream & operator<<(ostream &out, const CurrentAccount &v);
};

