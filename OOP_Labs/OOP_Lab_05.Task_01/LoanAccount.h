#pragma once

#include "BankAccount.h"

class LoanAccount : public BankAccount
{
private:

public:
	LoanAccount(const char* identifier, const char* ownerName, const char* ownerAddress, const double amount);
	~LoanAccount();
};

