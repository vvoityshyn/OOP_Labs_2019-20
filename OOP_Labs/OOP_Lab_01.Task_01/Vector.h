#pragma once\

class Vector
{
private:
	double a;
	double b;
public:
	Vector(double a, double b);
	~Vector();

	double GetA();
	double GetB();

	void SetA(double a);
	void SetB(double b);

	double Length();
};

