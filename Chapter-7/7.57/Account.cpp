#include "Account.h"

double Account::interestRate = 0;

void Account::rate(double r)
{
	interestRate = r;
}

double Account::initRate()
{
	return 0;
}
