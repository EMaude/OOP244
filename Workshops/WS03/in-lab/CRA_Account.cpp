// Elliot Maude
// 032830127

#include <iostream>
#include <cstring>
#include "CRA_Account.h"

using namespace std;

namespace sict
{
	void CRA_Account::set(const char * familyName, const char * givenName, int sin)
	{
		if (sin > min_sin && sin < max_sin)
		{
			m_sin = sin;
			strcpy(m_familyName, familyName);
			strcpy(m_givenName, givenName);
		}
		else
		{
			m_sin = 0;
		}
	}
	bool CRA_Account::isEmpty() const
	{
		return (m_sin != 0) ? false : true;
	}
	void CRA_Account::display() const
	{
		if (isEmpty())
		{
			cout << "Account object is empty!" << endl;
		}
		else
		{
			cout << "Family Name: " << m_familyName << endl;
			cout << "Given Name : " << m_givenName << endl;
			cout << "CRA Account: " << m_sin << endl;
		}
	}
}