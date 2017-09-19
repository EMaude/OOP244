#include "Kingdom.h"
/***********************************************************
// OOP244 Workshop 2: Dynamic Memory
// File Kingdom.cpp
// Version 1.0
// Date ???????????
// Author ?????????
// Description
// ?????????????????????
//
//
// Revision History
///////////////////////////////////////////////////////////
// Name     Date    Reason
// 
///////////////////////////////////////////////////////////
***********************************************************/


// TODO: include the necessary headers

// TODO: the sict namespace

    // TODO:definition for display(...) 

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

void sict::display(const Kingdom &kingdom)
{
	std::cout << kingdom.m_name << ", population " << kingdom.m_population << std::endl;
}