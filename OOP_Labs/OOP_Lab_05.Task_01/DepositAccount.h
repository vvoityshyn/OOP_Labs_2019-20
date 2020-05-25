#pragma once
#include "BankAccount.h"
#include "Date.h"
#include "DepositInterest.h"

class DepositAccount : public BankAccount
{
private:
	double rate;
	Date *creationDate;
	const int N = 1;

	DepositInterest* depositInterest;

protected:

	void Print(ostream & out) const;

public:
	DepositAccount(
		const char* identifier, 
		const char* ownerName, 
		const char* ownerAddress, 
		const double amount,
		const double rate,
		const Date &creationDate,
		DepositInterest* depositInterest);
	
	~DepositAccount();	

	const double GetAmount() const;

	/*
		Validation rule: creationDate <= date
	*/
	const double GetAmount(const Date &date) const;

	void PutFunds(const double amount);
	void WithdrawFunds(const double amount);

	//friend ostream & operator<<(ostream &out, const DepositAccount &v);

};
