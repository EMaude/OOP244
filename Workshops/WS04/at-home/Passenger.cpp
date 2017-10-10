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
			cout << m_name << " - " << m_dest << endl;
		}
	}
}