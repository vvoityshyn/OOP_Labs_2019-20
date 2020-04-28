#include <iostream>

#include "BankAccount.h"
#include "DepositAccount.h"
#include "CurrentAccount.h"
#include "Date.h"

using namespace std;

void TestVirtualMethods();

int main()
{
	cout << "OOP_Lab_05.Task_01" << endl;

	TestVirtualMethods();

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

	const int numberOfAccounts = 5;
	BankAccount* accounts[numberOfAccounts];

	accounts[0] = new CurrentAccount(identifier, ownerName, ownerAddress, amount);
	accounts[1] = new CurrentAccount(identifier, ownerName, ownerAddress, amount);
	accounts[2] = new DepositAccount(identifier, ownerName, ownerAddress, amount, rate, creationDate);
	accounts[3] = new DepositAccount(identifier, ownerName, ownerAddress, amount, rate, creationDate);
	accounts[4] = new DepositAccount(identifier, ownerName, ownerAddress, amount, rate, creationDate);

	for (int i = 0; i < numberOfAccounts; i++) {
		accounts[i]->PutFunds(10 * (i + 1));
		double amount = accounts[i]->GetAmount();
		cout << "Amount: " << amount << endl;
		cout << (*accounts[i]) << endl;
	}

	for (int i = 0; i < numberOfAccounts; i++) {
		delete accounts[i];
	}

}