/***********************************************************
// OOP244 Workshop 2: Dynamic Memory
// File Kingdom.h
// Version 1.0
// Date 9/19/17
// 
// Elliot Maude
//
***********************************************************/
#ifndef SICT_KINGDOM_H
#define SICT_KINGDOM_H

namespace sict
{
	struct Kingdom
	{
		char m_name[32];
		int	m_population;
	};

	void display(const Kingdom &kingdom);
}

#endif // !SICT_KINGDOM_H




