/**********************************************************
// OOP244 Workshop 2: Dynamic Memory
// File Kingdom.cpp
// Version 1.0
// Date 9/19/17
//
// Elliot Maude
//
***********************************************************/

#include <iostream>
#include "Kingdom.h"

using namespace std;

void sict::display(const Kingdom &kingdom)
{
	cout << kingdom.m_name << ", population " << kingdom.m_population << endl;
}

void sict::display(const Kingdom *kingdom, int size)
{
	int total_pop = 0;

	cout << "------------------------------" << endl;
	cout << "Kingdoms of SICT" << endl;
	cout << "------------------------------" << endl;

	for (int i = 0; i < size; i++)
	{
		cout << (i + 1) << ". " << kingdom[i].m_name << ", population " << kingdom[i].m_population << endl;
		
		total_pop += kingdom[i].m_population;
	}
	cout << "------------------------------" << endl;
	cout << "Total population of SICT: "<< total_pop << endl;
	cout << "------------------------------" << endl;
}
