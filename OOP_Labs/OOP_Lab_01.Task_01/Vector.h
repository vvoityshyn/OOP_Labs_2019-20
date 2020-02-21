#pragma once

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
	
	// not a copy constructor
	//Vector(const Vector* vector);

	// copy constructor
	Vector(const Vector& vector);

	~Vector();

	double GetA();
	double GetB();

	void SetA(double a);
	void SetB(double b);

	double Length();
};

