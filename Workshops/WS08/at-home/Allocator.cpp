// OOP244 Workshop 8: Virtual Functions and Abstract Base Classes
// File: Allocator.cpp
// Version: 2.0
// Date: 2017/12/11
// Author: Chris Szalwinski, based on previous work by Heidar Davoudi
// Description:
// This file allocates an Account object in dynamic memory
///////////////////////////////////////////////////
#include "SavingsAccount.h" 
#include "ChequingAccount.h"

namespace sict {

	const double interestRate = 0.05;
	const double transactionFee = 0.50;
	const double monthlyFee = 2.00;
	iAccount* CreateAccount(const char* type, double bal)
	{
		iAccount* newAccount = nullptr;

		if (type[0] == 'S')
		{
			newAccount = new SavingsAccount(bal, interestRate);
		}

		if (type[0] == 'C')
		{
			newAccount = new ChequingAccount(bal, transactionFee, monthlyFee);
		}

		return newAccount;
	}
}
