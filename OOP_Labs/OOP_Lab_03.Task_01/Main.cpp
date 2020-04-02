#include <iostream>
#include "Vector.h"

using namespace std;

void printVector(const Vector &v);
void TestPlusOperator();
void TestPlusAssignOperator();
void TestIndexingOperator();

int main()
{
	cout << "OOP_Lab_03.Task_01" << endl;

	{
		// TestPlusOperator();

		// TestIndexingOperator();

		TestPlusAssignOperator();

	}

	system("pause");
	return 0;
}

void TestIndexingOperator()
{
	cout << "TestIndexingOperator" << endl;

	Vector v(2, 4);

	printf("vector: (%f, %f)\n", v[1], v[2]);

	v[1] = 5.0;
	v[2] = 7.0;

	printf("vector: (%f, %f)\n", v[1], v[2]);
}

void TestPlusOperator()
{
	cout << "TestPlusOperator" << endl;

	Vector v1(1, 1);
	Vector v2(2, 2);

	Vector v3 = v1 + v2;

	printVector(v3);
}

void TestPlusAssignOperator()
{
	Vector v1(1, 1);
	Vector v2(2, 2);

	v2 += v1;
	printVector(v2);
}

void printVector(const Vector &v)
{
	printf("print vector: (%f, %f)\n", v.GetA(), v.GetB());
}