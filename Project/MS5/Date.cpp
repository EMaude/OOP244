//Elliot Maude
//032830127

#include "Date.h"

namespace sict {

	//***************
	//Private Methods
	//***************

	//Number of days in month mon_ and year year_
	int Date::mdays(int mon, int year)const {
		int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, -1 };
		int month = mon >= 1 && mon <= 12 ? mon : 13;
		month--;
		return days[month] + int((month == 1)*((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0));
	}
	void Date::errCode(int errorCode)
	{
		if (errorCode >= 0 && errorCode <= 4)
		{
			m_err = errorCode;
		}
		else
		{
			m_err = NO_ERROR;
		}
	}

	//***************
	//Constructors
	//***************

	Date::Date()
	{
		m_err = NO_ERROR;
		m_year = 0;
		m_month = 0; 
		m_day = 0;
		m_comp = 0;
	}
	Date::Date(int y, int m, int d)
	{
		if(y >= min_year && y <= max_year)
		{
			if (m > 0 && m < 13)
			{
				if (d > 0 && d <= mdays(m, y))
				{
					m_year = y;
					m_month = m;
					m_day = d;

					m_comp = (m_year * 372) + (m_month * 13) + m_day;

					errCode(NO_ERROR);
				}
				else
				{
					*this = Date();
					errCode(DAY_ERROR);
				}
			}
			else
			{
				*this = Date();
				errCode(MON_ERROR);
			}
		}
		else
		{
			*this = Date();
			errCode(YEAR_ERROR);
		}
	}
	Date::~Date()
	{

	}
	//***************
	//Operators
	//***************

	bool Date::operator==(const Date & rhs) const
	{
		if (isEmpty() || rhs.isEmpty())
		{
			return false;
		}
		else
		{
			return this->m_comp == rhs.m_comp;
		}
	}
	bool Date::operator!=(const Date & rhs) const
	{
		if (isEmpty() || rhs.isEmpty())
		{
			return false;
		}
		else
		{
			return this->m_comp != rhs.m_comp;
		}
	}
	bool Date::operator<(const Date & rhs) const
	{
		if (isEmpty() || rhs.isEmpty())
		{
			return false;
		}
		else
		{
			return this->m_comp < rhs.m_comp;
		}
	}
	bool Date::operator>(const Date & rhs) const
	{
		if (isEmpty() || rhs.isEmpty())
		{
			return false;
		}
		else
		{
			return this->m_comp > rhs.m_comp;
		}
	}
	bool Date::operator<=(const Date & rhs) const
	{
		if (isEmpty() || rhs.isEmpty())
		{
			return false;
		}
		else
		{
			return this->m_comp <= rhs.m_comp;
		}
	}
	bool Date::operator>=(const Date & rhs) const
	{
		if (isEmpty() || rhs.isEmpty())
		{
			return false;
		}
		else
		{
			return this->m_comp >= rhs.m_comp;
		}
	}

	//***************
	//Public Methods
	//***************

	int Date::errCode() const
	{
		return m_err;
	}
	bool Date::bad() const
	{
		return m_err != 0;
	}
	bool Date::isEmpty() const
	{
		if (m_year == 0 && m_month == 0 && m_day == 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	std::istream& Date::read(std::istream &istr)
	{
		int year;
		int month;
		int day;

		istr >> year;
		istr.ignore(1);
		istr >> month;
		istr.ignore(1);
		istr >> day;

		*this = Date(year, month, day);

		m_err = (istr.fail()) ? CIN_FAILED : m_err;

		return istr;
	}
	std::ostream& Date::write(std::ostream &ostr) const
	{
		ostr << m_year << "/";
		ostr.width(2);
		ostr.fill('0');
		ostr << m_month << "/";
		ostr.width(2);
		ostr.fill('0');
		ostr << m_day;
		return ostr;
	}

	//***************
	//Helper Functions
	//***************
	
	std::ostream& operator<<(std::ostream & ostr, const Date&d)
	{
		return d.write(ostr);
	}
	std::istream& operator>>(std::istream &istr, Date& d)
	{
		return d.read(istr);
	}

}
