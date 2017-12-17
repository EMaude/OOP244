// OOP244 Workshop 8: Virtual Functions and Abstract Base Classes
// File: Account.cpp
// Version: 2.0
// Date: 2017/12/11
// Author: Chris Szalwinski, based on previous work by Heidar Davoudi
// Description:
// This file implements the Account class
///////////////////////////////////////////////////

#include "Account.h"

namespace sict
{
	double Account::balance() const
	{
		return m_balance;
	}
	Account::Account()
	{
		m_balance = 0.0;
	}
	Account::Account(double in)
	{
		if (in > 0)
		{
			m_balance = in;
		}
		else
		{
			m_balance = 0.0;
		}
	}
	bool Account::credit(double in)
	{
		bool state;
		if (in > 0)
		{
			m_balance += in;
			state = true;
		}
		else
		{
			state = false;
		}

		return state;
	}
	bool Account::debit(double in)
	{
		bool state;
		if (in > 0)
		{
			m_balance -= in;
			state = true;
		}
		else
		{
			state = false;
		}

		return state;
	}
}