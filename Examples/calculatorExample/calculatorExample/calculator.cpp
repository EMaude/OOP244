#include "calculator.h"

#if 1
#include <iostream>
using namespace std;
#endif

double power(int base, int exp)
{
	int i;
	double result = 1;
	bool isNeg = false;

	if (exp < 0)
	{
		exp *= -1;
		isNeg = true;
	}

	for (i = 0; i < exp; i++)
	{
		result *= base;
	}

	return (isNeg) ? (1 / result) : result;
}

double exponent(double result, int base)
{
	int exp = 0;
	
	if (result < 1)
	{
		exp = 1;
		while (result != 1 / (base * exp))
		{
			exp++;
		}
	}
	else
	{
		while (result >= base)
		{
			exp++;
			result /= base;
		}
	}

	return exp;
}
