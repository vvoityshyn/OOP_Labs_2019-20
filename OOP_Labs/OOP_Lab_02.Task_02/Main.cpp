#include <iostream>
#include "Vector.h"

using namespace std;

void PrintVector(Vector* vector);

int main()
{
	cout << "OOP_Lab_01.Task_01" << endl;

	try
	{
		Vector *a = new Vector(4);
		a->Set(0, 2.5);
		a->Set(1, 5.8);
		a->Set(2, 3.3);
		a->Set(3, 1.34);
		PrintVector(a);

		Vector *b = new Vector(5, -1.0);
		PrintVector(b);

		Vector *c = new Vector(*a);

		a->Set(0, -1);

		PrintVector(a);
		PrintVector(c);

		delete a;
		delete b;
		delete c;
	}
	catch (const char* message)
	{
		cout << "Error: " << message << endl;
	}

	system("pause");
	return 0;
}

void PrintVector(Vector* vector)
{
	cout << "[";
	for (int i = 0; i < vector-> Dim(); i++)
	{
		cout << vector->Get(i);
		if (i < vector->Dim() - 1)
		{
			cout << ", ";
		}
	}
	cout << "]"<<endl;
}