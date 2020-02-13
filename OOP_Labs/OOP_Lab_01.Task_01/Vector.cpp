#include <iostream>
#include "Vector.h"
#include <math.h>

using namespace std;

Vector::Vector(double a, double b)
{
	cout << "Vector::Vector(double a, double b)" << endl;
	this->a = a;
	this->b = b;
}

Vector::~Vector()
{
	cout << "Vector::~Vector()" << endl;
}

double Vector::GetA()
{
	return this->a;
}

double Vector::GetB()
{
	return this->b;
}

void Vector::SetA(double a)
{
	this->a = a;
}

void Vector::SetB(double b)
{
	this->b = b;
}

double Vector::Length()
{
	return sqrt(a * a + b * b);
}
