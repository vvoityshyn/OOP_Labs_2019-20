#include <iostream>

#include "Account.h"

using namespace std;

int main()
{
	cout << "OOP_Lab_04.Task_01" << endl;

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

	system("pause");
	return 0;
}
