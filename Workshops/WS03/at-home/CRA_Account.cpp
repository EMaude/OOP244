// Elliot Maude
// 032830127

#include <iostream>
#include <math.h>
#include <cstring>
#include "CRA_Account.h"

using namespace std;

namespace sict
{
	bool CRA_Account::validSIN() const
	{
		int first = m_sin % 10;
		int temp = m_sin / 10;

		int set1[4];
		int set2[4];
		
		for (int i = 8; i > 0; i += 2)
		{
			set1[i] = (temp % 10) + (temp % 10);
			temp /= 10;
			set2[i + 1] = temp % 10;
			temp /= 10;
		}

		int temp1, temp2;

		for (int i = 0; i < 4; i++)
		{
			temp1 = set1[i] * int(pow(10, i));
			temp2 = set2[i] * int(pow(10, i));
		}

		int fsum = 0, lsum = 0;

		while (temp1 % 10 != 0)
		{
			fsum += temp % 10;
			temp /= 10;
		}

		while (temp2 % 10 != 0)
		{
			lsum += temp % 10;
			temp /= 10;
		}

		int sum = fsum + lsum;
		sum = sum % 10;
		sum = sum - 10;

		return (first == sum)? true : false;
	}
	void CRA_Account::set(const char * familyName, const char * givenName, int sin)
	{
		if (sin > min_sin && sin < max_sin)
		{
			m_sin = sin;
			strcpy(m_familyName, familyName);
			strcpy(m_givenName, givenName);
			m_storedYrs = 0;
		}
		else
		{
			m_sin = 0;
		}
	}

	void sict::CRA_Account::set(int year, double balance)
	{
		if (isEmpty())
		{
			cout << "Account object is empty!" << endl;
		}
		else
		{
			if (m_storedYrs < max_yrs)
			{
				m_years[m_storedYrs] = year;
				m_balance[m_storedYrs] = balance;
				m_storedYrs++;
			}
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