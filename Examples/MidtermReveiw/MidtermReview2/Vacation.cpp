#include "cstring"
#include "Vacation.h"


Vacation::Vacation(const Vacation &a)
{
	if (this != &a)
	{
		*this = a;
	}
}

Vacation & Vacation::operator=(const Vacation &a)
{
	if (this != &a)
	{
		int size = strlen(a.m_destination);
		//shallow copy
		this->m_totalCost = a.m_totalCost;
		//remove old memory
		delete[] this->m_destination;
		this->m_destination = new char[size];
		strcpy(this->m_destination, a.m_destination);
	}
	return *this;
}
