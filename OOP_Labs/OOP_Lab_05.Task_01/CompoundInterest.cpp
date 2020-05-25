#include "CompoundInterest.h"

CompoundInterest::CompoundInterest(int n)
{
	this->n = n;
}

double CompoundInterest::CalculateAmount(double startAmount, double rate, Date creationDate, Date targetDate)
{
	double p0 = startAmount;
	double t = this->GetNumberOfWholeYears(creationDate, targetDate);
	double r = rate;
	double n = this->n;
	double p = p0 * pow(1 + r / n, n * t);
	return p;	
}
