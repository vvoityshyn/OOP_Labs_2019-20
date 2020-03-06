#include <iostream>
#include "Vector.h"
#include <math.h>

using namespace std;

void Vector::InitVector(int n, double value)
{
	this->n = n;
	this->v = new double[this->n];
	for (int i = 0; i < this->n; i++)
	{
		this->v[i] = value;
	}
}

Vector::Vector()
{
	cout << "Vector::Vector()" << endl;

	InitVector(1, 0.0);
}

Vector::Vector(int n)
{
	cout << "Vector::Vector(int n)" << endl;

	if (n <= 0)
	{
		throw "Incorrect dimension of the vector";
	}

	InitVector(n, 0.0);
}

Vector::Vector(int n, double value)
{
	cout << "Vector::Vector(int n, double value)" << endl;

	if (n <= 0)
	{
		throw "Incorrect dimension of the vector";
	}

	InitVector(n, value);
}

Vector::Vector(const Vector& vector)
{
	cout << "Vector::Vector(const Vector& vector)" << endl;
	this->n = vector.n;
	this->v = new double[this->n];
	for (int i = 0; i < this->n; i++)
	{
		this->v[i] = vector.v[i];
	}
}

Vector::~Vector()
{
	delete [] this->v;
	cout << "Vector::~Vector()" << endl;
}

double Vector::Get(int i)
{
	if (i < 0 || i >= n)
	{
		throw "Incorrect index of the vector's element";
	}
	return this->v[i];
}

void Vector::Set(int i, double value)
{
	if (i < 0 || i >= n)
	{
		throw "Incorrect index of the vector's element";
	}
	this->v[i] = value;
}

int Vector::Dim()
{
	return this->n;
}

double Vector::Abs()
{
	double l = 0.0;
	for (int i = 0; i < this->n; i++)
	{
		l += this->v[i] * this->v[i];
	}
	return sqrt(l);
}