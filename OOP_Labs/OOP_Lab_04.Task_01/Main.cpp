#include <iostream>

#include "Account.h"
#include "DepositAccount.h"
#include "Date.h"

using namespace std;

void TestAccount();
void TestDepositAccount_CompoundInterest();
void TestMethodsInheritance();

int main()
{
	/*
		ToDo:
			1. Validation for date
			2. IncAmount() && DecAmount() for date
			3. Динамічне / статичне зв'язування
			4. UML class diagram
	*/

	cout << "OOP_Lab_04.Task_01" << endl;

	//TestAccount();
	//TestDepositAccount();
	TestMethodsInheritance();

	system("pause");
	return 0;
}

void TestAccount()
{
	char identifier[] = "UA213223130000026007233566001";
	char ownerName[] = "John Smith";
	char ownerAddress[] = "Lviv, Ukraine";
	double amount = 100.0;

	Account account(identifier, ownerName, ownerAddress, amount);

	cout << account << endl;

	ownerName[0] = '1';
	ownerName[1] = '2';
	ownerName[2] = '3';

	cout << account << endl;

	account.IncAmount(20);

	cout << account << endl;

	account.DecAmount(30);

	cout << account << endl;
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

	DepositAccount depositAccount(identifier, ownerName, ownerAddress, amount, rate, creationDate);
	
	double p = depositAccount.GetAmount(date);

	cout << "Deposit account amount: " << p << endl;

	cout << depositAccount << endl;

}

void TestMethodsInheritance() {
	char identifier[] = "UA213223130000026007233566001";
	char ownerName[] = "John Smith";
	char ownerAddress[] = "Lviv, Ukraine";
	double amount = 100.0;
	double rate = 0.1;
	Date creationDate(2017, 2, 2);
	Date date(2020, 4, 16);

	Account* depositAccount = new DepositAccount(identifier, ownerName, ownerAddress, amount, rate, creationDate);

	// Static linking
	depositAccount->IncAmount(100);
	depositAccount->DecAmount(20);

	cout << *depositAccount << endl;

	delete depositAccount;

}