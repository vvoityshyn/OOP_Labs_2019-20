#include <iostream>
#include "Vector.h"

using namespace std;

void printVector(Vector v);

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

		Vector v2(0, 0);
		v2 = v1; // the copy constructor is not executed

		printf("v2: (%f, %f)\n", v2.GetA(), v2.GetB());

		v1.SetA(4);
		v1.SetB(5);
		printf("v1: (%f, %f)\n", v1.GetA(), v1.GetB());

		printf("v2: (%f, %f)\n", v2.GetA(), v2.GetB());

		// copy constructor
		printVector(v1);

		// copy constructor
		Vector v3 = v1; 

		Vector v4;
		printf("v4: (%f, %f)\n", v4.GetA(), v4.GetB());
	}

	system("pause");
	return 0;
}

void printVector(Vector v)
{
	printf("vector: (%f, %f)\n", v.GetA(), v.GetB());
}