// OOP244 Workshop 8: Virtual Functions and Abstract Base Classes
// File: Allocator.cpp
// Version: 2.0
// Date: 2017/12/11
// Author: Chris Szalwinski, based on previous work by Heidar Davoudi
// Description:
// This file allocates an Account object in dynamic memory
///////////////////////////////////////////////////
#include "SavingsAccount.h" 

namespace sict {

	const double interestRate = 0.05;

	iAccount* CreateAccount(const char* type, double in)
	{
		iAccount* newAccount = nullptr;

		if (type[0] == 'S')
		{
			newAccount = new SavingsAccount(in, interestRate);
		}

		return newAccount;
	}
}
