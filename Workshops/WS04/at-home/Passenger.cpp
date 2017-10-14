#include <cstring>
#include <iostream>
#include <iomanip>
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
		if (name == nullptr || dest == nullptr)
		{
			*this = Passenger();
		}
		else
		{
			strcpy(m_name, name);
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
			*this = Passenger();
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
			cout << setfill('0');
			cout << m_name << " - " << m_dest << " on " << m_year << "/" << setw(2) << m_month << "/" << setw(2) << m_day << endl;
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
		bool state = false;

		if (strcmp(pass.m_dest, this->m_dest) == 0)
		{
			if (pass.m_year == this->m_year)
			{
				if (pass.m_month == this->m_month)
				{
					if (pass.m_day == this->m_day)
					{
						state = true;
					}
				}
			}
		}
		return state;
	}
}