#include <iostream>
#include "Vector.h"
#include <math.h>

using namespace std;

Vector::Vector()
{
	cout << "Vector::Vector()" << endl;
	this->a = 0;
	this->b = 0;
}

Vector::Vector(double a, double b)
{
	printf("Vector::Vector(double %lf, double %lf)\n", a, b);
	this->a = a;
	this->b = b;
}

Vector::Vector(const Vector& vector)
{
	cout << "Vector::Vector(const Vector& vector)" << endl;
	this->a = vector.a;
	this->b = vector.b;
}

Vector::~Vector()
{
	cout << "Vector::~Vector()" << endl;
}

double Vector::GetA() const
{
	return this->a;
}

double Vector::GetB() const
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

double Vector::Length() const
{
	return sqrt(a * a + b * b);
}

Vector & Vector::operator=(const Vector &v)
{
	this->a = v.a;
	this->b = v.b;
	return *this;
}

Vector operator+(const Vector & v1, const Vector & v2)
{
	double a = v1.a + v2.a;
	double b = v1.b + v2.b;

	Vector v(a, b);

	return v;
}

Vector operator*(const double number, const Vector & v)
{
	Vector w(number * v[1], number * v[2]);
	return w;
}

Vector operator*(const Vector & v, const double number)
{
	Vector w(number * v[1], number * v[2]);
	return w;
}

double & Vector::operator[](const int index)
{
	if (1 == index)
	{
		return this->a;
	}
	else if (2 == index)
	{
		return this->b;
	}
	else
	{
		throw "Incorrect index";
	}
}

const double & Vector::operator[](const int index) const
{
	if (1 == index)
	{
		return this->a;
	}
	else if (2 == index)
	{
		return this->b;
	}
	else
	{
		throw "Incorrect index";
	}
}

Vector & Vector::operator+=(const Vector & right)
{
	this->a += right.a;
	this->b += right.b;
	return *this;
}

bool operator<(const Vector & v1, const Vector & v2)
{
	return (v1.Length() < v2.Length());
}

ostream & operator<<(ostream & out, const Vector & v)
{
	out << "(" << v.GetA() << "; " << v.GetB() << ")";	
	return out;
}
