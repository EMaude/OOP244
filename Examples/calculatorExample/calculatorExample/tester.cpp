#include <iostream>

using namespace std;

#include "calculator.h"

int testSuite(int BASE, int EXPONENT,double RESULT)
{
	int passed = 0;
	double result;

	result = power(BASE, EXPONENT);
	if (result == RESULT)
	{
		cout << "Power Test Passed" << endl;
		passed++;
	}
	else
	{
		cout << "Power Test Failed, Result: " << result << endl;
	}

	result = exponent(RESULT, BASE);
	if (result == EXPONENT)
	{
		cout << "Exponent Test Passed" << endl;
		passed++;
	}
	else
	{
		cout << "Exponent Test Failed, Result: " << result << endl;
	}
	return passed;
}