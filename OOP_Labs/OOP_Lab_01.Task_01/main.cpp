#include <iostream>
#include "Vector.h"
#include "main.h"

using namespace std;

int main()
{
	cout << "OOP_Lab_01.Task_01" << endl;

	{
		Vector v1(1, 1);

		double l1 = v1.Length();
		cout << "Length of v1 = " << l1 << endl;

		printf("v1: (%f, %f)\n", v1.GetA(), v1.GetB());

		v1.SetA(2);
		v1.SetB(3);
		printf("v1: (%f, %f)\n", v1.GetA(), v1.GetB());

	}

	system("pause");
	return 0;
}