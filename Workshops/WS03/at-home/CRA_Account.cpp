// Elliot Maude
// 032830127

#include <iostream>
#include <math.h>
#include <cstring>
#include "CRA_Account.h"

using namespace std;

namespace sict
{
	bool CRA_Account::validSIN(int sin) const
	{
		int first = sin % 10, temp = sin / 10; 
		int lsum = 0, fsum = 0;
		int s1;

		//break sin digits into 2 sets, first set adds to itself
		for (int i = 0; i < 4; i++)
		{
			s1 = (temp % 10) + (temp % 10);
			fsum += ((s1 / 10) > 0) ? ((s1 % 10) + (s1 / 10)): s1; //add set1's digits together
			temp /= 10;
			lsum += temp % 10; // add set2 digits together (set2s digits can never be < 10 so no check is need)
			temp /= 10;
		}

		//add the two sums and find the nearest multiple of 10
		int sum = fsum + lsum;
		sum = sum % 10;
		sum = 10 - sum;

		return (first == sum)? true : false;
	}
	void CRA_Account::set(const char * familyName, const char * givenName, int sin)
	{

		if (validSIN(sin))
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
		return (m_sin != 0 && strlen(m_familyName) > 1 && strlen(m_givenName) > 1) ? false : true;
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
			
			for (int i = 0; i < m_storedYrs; i++)
			{
				if (m_balance[i] > 2)
				{
					cout << "Year (" << m_years[i] << ") balance owing: " << m_balance[i] << endl;
				}
				else if (m_balance[i] < -2)
				{
					cout << "Year (" << m_years[i] << ") refund due: " << (m_balance[i] * -1.00) << endl;
				}
				else
				{
					cout << "Year (" << m_years[i] << ") No balance owing or refund due!" << endl;
				}
			}
		}
	}
}