#include <iostream>

#include "BankAccount.h"
#include "DepositAccount.h"
#include "CurrentAccount.h"
#include "Date.h"
#include "CompoundInterest.h"
#include "SimpleInterest.h"

using namespace std;

void TestVirtualMethods();
void TestDepositAccount_CompoundInterest();
void TestDepositAccount_SimpleInterest();

int main()
{
	cout << "OOP_Lab_05.Task_01" << endl;

	//TestVirtualMethods();
	TestDepositAccount_CompoundInterest();
	TestDepositAccount_SimpleInterest();

	system("pause");
	return 0;
}

void TestVirtualMethods() {
	char identifier[] = "UA213223130000026007233566001";
	char ownerName[] = "John Smith";
	char ownerAddress[] = "Lviv, Ukraine";
	double amount = 100.0;
	double rate = 0.1;
	Date creationDate(2017, 2, 2);
	Date date(2020, 4, 16);
	DepositInterest *depositAmountFormula = new CompoundInterest(1);

	const int numberOfAccounts = 5;
	BankAccount* accounts[numberOfAccounts];

	accounts[0] = new CurrentAccount(identifier, ownerName, ownerAddress, amount);
	accounts[1] = new CurrentAccount(identifier, ownerName, ownerAddress, amount);
	accounts[2] = new DepositAccount(identifier, ownerName, ownerAddress, amount, rate, creationDate, depositAmountFormula);
	accounts[3] = new DepositAccount(identifier, ownerName, ownerAddress, amount, rate, creationDate, depositAmountFormula);
	accounts[4] = new DepositAccount(identifier, ownerName, ownerAddress, amount, rate, creationDate, depositAmountFormula);

	for (int i = 0; i < numberOfAccounts; i++) {
		accounts[i]->PutFunds(10 * (i + 1));
		double amount = accounts[i]->GetAmount();
		cout << "Amount: " << amount << endl;
		cout << (*accounts[i]) << endl;
	}

	for (int i = 0; i < numberOfAccounts; i++) {
		delete accounts[i];
	}

	delete depositAmountFormula;

}

void TestDepositAccount_CompoundInterest()
{
	char identifier[] = "UA213223130000026007233566001";
	char ownerName[] = "John Smith";
	char ownerAddress[] = "Lviv, Ukraine";
	double amount = 100.0;
	double rate = 0.1;
	Date creationDate(2017, 2, 2);
	Date date(2020, 4, 16);
	DepositInterest* depositAmountFormula = new CompoundInterest(1);

	DepositAccount *depositAccount = new DepositAccount(
		identifier, 
		ownerName, 
		ownerAddress, 
		amount, 
		rate, 
		creationDate, 
		depositAmountFormula);

	double targetAmount = depositAccount->GetAmount(date);

	cout << "Amount : " << targetAmount << endl;

	delete depositAccount;
	delete depositAmountFormula;
}

void TestDepositAccount_SimpleInterest()
{
	char identifier[] = "UA213223130000026007233566001";
	char ownerName[] = "John Smith";
	char ownerAddress[] = "Lviv, Ukraine";
	double amount = 100.0;
	double rate = 0.1;
	Date creationDate(2017, 2, 2);
	Date date(2020, 4, 16);
	DepositInterest* depositAmountFormula = new SimpleInterest();

	DepositAccount* depositAccount = new DepositAccount(
		identifier,
		ownerName,
		ownerAddress,
		amount,
		rate,
		creationDate,
		depositAmountFormula);

	double targetAmount = depositAccount->GetAmount(date);

	cout << "Amount : " << targetAmount << endl;

	delete depositAccount;
	delete depositAmountFormula;
}