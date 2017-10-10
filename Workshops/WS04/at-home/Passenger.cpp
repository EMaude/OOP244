#include <cstring>
#include <iostream>
#include "Passenger.h"

using namespace std;

namespace sict
{

	Passenger::Passenger()
	{
		strcpy(m_name, "");
		strcpy(m_dest, "");
	}

	Passenger::Passenger(const char* name, const char* dest)
	{
		//Name
		if (name == nullptr)
		{
			strcpy(m_name, "");
		}
		else
		{
			strcpy(m_name, name);
		}
		//Dest
		if (dest == nullptr)
		{
			strcpy(m_dest, "");
		}
		else
		{
			strcpy(m_dest, dest);
		}

		m_year = 2017;
		m_month = 7;
		m_day = 1;

	}

	Passenger::Passenger(const char * name, const char * dest, int year, int month, int day)
	{
		*this = Passenger(name, dest);
	
		if (2017 <= year && year <= 2020 && 1 <= month && month <= 12 && 1 <= day && day <= 31)
		{
			m_year = year;
			m_month = month;
			m_day = day;
		}
		else
		{	//Safe Empty state
			strcpy(m_name, "");
			strcpy(m_dest, "");
			m_year = 2017;
			m_month = 7;
			m_day = 1;
		}
	}

	Passenger::~Passenger()
	{
	}

	bool Passenger::isEmpty() const
	{
		return (strcmp(m_name, "") == 0 || strcmp(m_dest, "") == 0) ? true : false;
	}

	void Passenger::display() const
	{
		if (isEmpty())
		{
			cout << "No passenger!" << endl;
		}
		else
		{	
			cout.precision(2);
			cout << m_name << " - " << m_dest << " on " << m_year << "/" << m_month << "/" << m_day << endl;
		}
	}

	const char* Passenger::name() const
	{
		if (isEmpty())
		{
			return "";
		}
		else
		{
			return m_name;
		}
	}

	bool Passenger::canTravelWith(const Passenger& pass) const
	{
		if (pass.isEmpty())
		{
			return false;
		}
		else
		{
			if (pass.m_dest == m_dest)
			{
				if (pass.m_year == m_year && pass.m_month == m_month && pass.m_day == m_day)
				{
					return true;
				}
			}
		}
	}
}