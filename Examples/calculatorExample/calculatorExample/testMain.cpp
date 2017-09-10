// Calculator Example Pg 18 - 20

#include <iostream>

using namespace std;

#include "tester.h"

int main(void)
{
	int passed = 0;
	passed += testSuite(5, 3, 125);
	passed += testSuite(5, -3, 0.008);
	cout << passed << " Tests Passed" << endl;
	return 0;
}