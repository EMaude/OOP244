// OOP244 Workshop 8: Virtual Functions and Abstract Base Classes
// File: ChequingAccount.cpp
// Version: 2.0
// Date: 2017/12/11
// Author: Chris Szalwinski, based on previous work by Heidar Davoudi
// Description:
// This file implements the ChequingAccount class
///////////////////////////////////////////////////

#include "ChequingAccount.h"

using namespace std;

namespace sict {
	ChequingAccount::ChequingAccount(double bal, double tran, double month) : Account(bal)
	{
		m_transactionFee = (tran > 0)? tran : 0.0;
		m_monthlyFee = (month > 0) ? month : 0.0;
	}
	bool ChequingAccount::credit(double in)
	{
		bool state;
		if (Account::credit(in))
		{
			Account::debit(m_transactionFee);
			state = true;
		}
		else
		{
			state = false;
		}
		return state;
	}
	bool ChequingAccount::debit(double in)
	{
		bool state;
		if (Account::debit(in))
		{
			Account::debit(m_transactionFee);
			state = true;
		}
		else
		{
			state = false;
		}
		return state;
	}
	void ChequingAccount::monthEnd()
	{
		debit(m_monthlyFee);
	}
	void ChequingAccount::display(std::ostream &os) const
	{
		os << "Account type: Chequing" << endl;
		os.precision(2);
		os << fixed << "Balance: $" << Account::balance() << endl;
		os << "Per Transaction Fee: " << m_transactionFee << endl;
		os << "Monthly Fee: " << m_monthlyFee << endl;
	}
}