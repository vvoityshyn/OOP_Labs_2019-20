#include <iostream>

#include "Account.h"
#include "DepositAccount.h"
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
	Account* accounts[numberOfAccounts];

	accounts[0] = new Account(identifier, ownerName, ownerAddress, amount);
	accounts[1] = new Account(identifier, ownerName, ownerAddress, amount);
	accounts[2] = new DepositAccount(identifier, ownerName, ownerAddress, amount, rate, creationDate);
	accounts[3] = new DepositAccount(identifier, ownerName, ownerAddress, amount, rate, creationDate);
	accounts[4] = new DepositAccount(identifier, ownerName, ownerAddress, amount, rate, creationDate);

	for (int i = 0; i < numberOfAccounts; i++) {
		accounts[i]->IncAmount(10 * (i + 1));
	}

	for (int i = 0; i < numberOfAccounts; i++) {
		delete accounts[i];
	}

}