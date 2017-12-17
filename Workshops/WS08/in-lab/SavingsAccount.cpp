// OOP244 Workshop 8: Virtual Functions and Abstract Base Classes
// File: SavingsAccount.cpp
// Version: 2.0
// Date: 2017/12/11
// Author: Chris Szalwinski, based on previous work by Heidar Davoudi
// Description:
// This file implements the SavingsAccount class
///////////////////////////////////////////////////

#include "SavingsAccount.h"

using namespace std;

namespace sict
{
	SavingsAccount::SavingsAccount(double bal, double interest) : Account(bal)
	{
		if (interest > 0)
		{
			m_interest = interest;
		}
		else
		{
			m_interest = 0.0;
		}
	}
	void SavingsAccount::monthEnd()
	{
		double bal = Account::balance();
		Account::credit(bal * m_interest);
	}
	void SavingsAccount::display(std::ostream &os) const
	{
		os << "Account type: Savings" << endl;
		os.precision(2);
		os << fixed << "Balance: $" << Account::balance() << endl;
		os << "Interest Rate (%): " << m_interest * 100 << endl;
	}
}