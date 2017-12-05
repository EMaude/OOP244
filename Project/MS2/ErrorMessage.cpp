//Elliot Maude
//032830127
#define _CRT_SECURE_NO_WARNINGS
#include "ErrorMessage.h"

namespace sict
{
	ErrorMessage::ErrorMessage(const char* errorMessage)
	{
		if (errorMessage != nullptr)
		{
			message(errorMessage);
		}
		else
		{
			clear();
		}
	}
	ErrorMessage::~ErrorMessage()
	{
		delete[] m_message;
		m_message = nullptr;
	}
	void ErrorMessage::clear()
	{
		if (m_message != nullptr)
		{
			delete[] m_message;
		}

		m_message = new char[1];
		strcpy(m_message, "");
	}
	bool ErrorMessage::isClear() const
	{
		if (m_message == nullptr || strcmp(m_message, "") == 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	void ErrorMessage::message(const char * str)
	{
		if (str != nullptr)
		{
			int size = strlen(str);
			delete[] m_message;
			m_message = new char[size];
			strcpy(m_message, str);
		}
		else
		{
			clear();
		}
	}
	const char* ErrorMessage::message() const
	{
		return m_message;
	}
	ostream& operator<<(ostream& os, const ErrorMessage& message)
	{
		return os;
	}
}
