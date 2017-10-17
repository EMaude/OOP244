#include <iostream>
#include <cstring>
#include "Contact.h"

using namespace std;

namespace sict
{
	//--------------------------
	//Constructors - Destructor
	//--------------------------

	Contact::Contact()
	{
		//Safe empty state
		strcpy(m_name, "");
		m_size = 0; 
		m_pPhoneNumbers = new long long[1];
		m_pPhoneNumbers[0] = 0;

	}
	Contact::Contact(const char *name, const long long *phoneNumbers, int size)
	{
		//if data is valid
		if (name != nullptr && strcmp(name, "") != 0)		{
			//Copy data to object
			strncpy(m_name, name, 19);
			//Dynamic memory
			phoneNumberAllocation(phoneNumbers, size);
		}
		else
		{
			//Safe Empty State
			*this = Contact();
		}
	}
	Contact::Contact(const Contact &a)
	{
			*this = a;
	}
	Contact::~Contact()
	{
		delete[] m_pPhoneNumbers;
		m_pPhoneNumbers = nullptr;
	}

	//---------------
	//Private Members
	//---------------
	void Contact::phoneNumberAllocation(const long long * phoneNumbers, int size)
	{
		//Pre allocate to a safe state
		m_pPhoneNumbers = new long long[1];
		m_pPhoneNumbers[0] = 0;

		m_size = 0;
		//check data validation and get size of valid data
		for (int i = 0; i < size; i++)
		{
			if (phoneNumbers[i] >= 10000000000 && phoneNumbers[i] <= 999999999999)
			{
				m_size += 1;
			}
		}
		if (m_size != 0)
		{
			//Allocate m_size memory
			delete[] m_pPhoneNumbers;
			m_pPhoneNumbers = new long long[m_size];

			//populate memory with data
			for (int i = 0, j = 0; i < size; i++)
			{
				if (phoneNumbers[i] >= 10000000000 && phoneNumbers[i] <= 999999999999)
				{
					if (j != m_size) //make sure j cannot overrun the array
					{
						m_pPhoneNumbers[j] = phoneNumbers[i];
						j++;
					}
				}
			}
		}
	}
	void Contact::addPhoneNumber(long long phoneNumber)
	{
		Contact temp = *this; //make a copy of this
		this->m_size += 1;
		if (phoneNumber >= 10000000000 && phoneNumber <= 999999999999)
		{
			delete[] this->m_pPhoneNumbers;
			this->m_pPhoneNumbers = new long long[this->m_size];
			
			for (int i = 0; i < temp.m_size; i++)
			{
				this->m_pPhoneNumbers[i] = temp.m_pPhoneNumbers[i];
			}
			this->m_pPhoneNumbers[this->m_size] = phoneNumber;
		}
	}

	//--------------
	//Public Members
	//--------------
	bool Contact::isEmpty() const
	{
		bool result = true;
		if (strcmp(m_name, ""))
		{
			result = false;
		}
		return result;
	}
	void Contact::display() const
	{
		if (isEmpty())
		{
			cout << "Empty contact!" << endl;
		}
		else
		{
			cout << m_name << endl;
			
			for (int i = 0; i < m_size; i++)
			{
				long long countryCode = m_pPhoneNumbers[i] / 10000000000;
				long long areaCode = (m_pPhoneNumbers[i] % 10000000000) / 10000000;
				long long num3 = (m_pPhoneNumbers[i] % 10000000) / 10000;
				long long num4 = (m_pPhoneNumbers[i] % 10000);
				
				cout << "(+" << countryCode << ") ";
				cout.fill('0');
				cout.width(3);
				cout << areaCode << " ";
				cout.fill('0');
				cout.width(3);
				cout << num3 << "-";
				cout.fill('0');
				cout.width(4);
				cout <<num4 << endl;
			}
		}
	}

	//---------
	//Operators
	//---------
	Contact& Contact::operator=(const Contact &a)
	{
		if (this != &a)
		{
			strcpy(this->m_name, a.m_name);
			this->m_size = a.m_size;
			
			delete[] this->m_pPhoneNumbers;
			m_pPhoneNumbers = new long long[this->m_size];

			for (int i = 0; i < this->m_size; i++)
			{
				m_pPhoneNumbers[i] = a.m_pPhoneNumbers[i];
			}
		}
		return *this;
	}
	Contact& Contact::operator+=(long long phoneNumber)
	{
		addPhoneNumber(phoneNumber);
		return *this;
	}
}