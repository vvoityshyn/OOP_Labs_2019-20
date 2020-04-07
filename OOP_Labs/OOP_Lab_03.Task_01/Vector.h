#pragma once

#include <iostream>

using namespace std;

class Vector
{
private:
	double a;
	double b;
public:
	// default constructor
	Vector();

	// constructor with parameters
	Vector(double a, double b);

	// copy constructor
	Vector(const Vector& vector);

	~Vector();

	double GetA() const;
	double GetB() const;

	void SetA(double a);
	void SetB(double b);

	double Length() const;

	Vector & operator=(const Vector &v);

	friend Vector operator+(const Vector &v1, const Vector &v2);
	//friend Vector & operator-(const Vector &v1, const Vector &v2);
	//friend double operator*(const Vector &v1, const Vector &v2);

	friend Vector operator*(const double number, const Vector &v);
	friend Vector operator*(const Vector &v, const double number);

	friend bool operator<(const Vector &v1, const Vector &v2);
	//friend bool operator>(const Vector &v1, const Vector &v2);
	//friend bool operator<=(const Vector &v1, const Vector &v2);
	//friend bool operator>=(const Vector &v1, const Vector &v2);
	//friend bool operator==(const Vector &v1, const Vector &v2);
	//friend bool operator!=(const Vector &v1, const Vector &v2);

	double & operator[](const int index);
	const double & operator[](const int index) const;

	Vector& operator+=(const Vector& right);
	//Vector& operator-=(const Vector& right);
	//Vector& operator*=(const double number);

	friend ostream & operator<<(ostream &out, const Vector &v);
};

