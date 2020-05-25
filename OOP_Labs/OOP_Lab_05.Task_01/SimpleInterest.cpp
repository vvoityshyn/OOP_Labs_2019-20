#include "SimpleInterest.h"

double SimpleInterest::CalculateAmount(double startAmount, double rate, Date creationDate, Date targetDate)
{
	double p0 = startAmount;
	double t = this->GetNumberOfWholeYears(creationDate, targetDate);
	double r = rate;	
	double p = p0 * (1 + r * t);
	return p;
}
