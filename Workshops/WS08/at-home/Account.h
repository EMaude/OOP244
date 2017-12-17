// OOP244 Workshop 8: Virtual Functions and Abstract Base Classes
// File: Account.h
// Version: 2.0
// Date: 2017/12/11
// Author: Chris Szalwinski, based on previous work by Heidar Davoudi
// Description:
// This file defines the Account class
///////////////////////////////////////////////////

#ifndef SICT_ACCOUNT_H__
#define SICT_ACCOUNT_H__

#include "iAccount.h"

namespace sict{
   
	class Account : public iAccount
	{
	private:
		double m_balance;

	protected:
		double balance() const;

	public:
		Account();
		Account(double);
		bool credit(double);
		bool debit(double);
	};


}
#endif
