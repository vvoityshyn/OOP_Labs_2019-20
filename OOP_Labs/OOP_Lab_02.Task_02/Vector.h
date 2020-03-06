#pragma once

class Vector
{
private:
	double *v;
	double n;

	void InitVector(int n, double value);

public:
	// default constructor
	Vector();

	// constructor with parameters
	Vector(int n);

	// constructor with parameters
	Vector(int n, double value);

	// copy constructor
	Vector(const Vector& vector);

	~Vector();

	double Get(int i);

	void Set(int i, double value);

	int Dim();

	double Abs();
};
