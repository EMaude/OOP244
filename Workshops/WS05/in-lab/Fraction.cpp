#include <iostream>
#include "Fraction.h"

using namespace std;

namespace sict
{
	//Constructors
	Fraction::Fraction()
	{
		m_numerator = -1;
		m_denominator = 0;
	}

	Fraction::Fraction(int numerator, int denominator)
	{
		if (numerator >= 0 && denominator > 0)
		{
			m_numerator = numerator;
			m_denominator = denominator;
			reduce();
		}
		else
		{
			*this = Fraction();
		}
	}
	//Private Members
	int Fraction::max() const
	{
		return (m_numerator > m_denominator) ? m_numerator : m_denominator;
	}

	int Fraction::min() const
	{
		return (m_numerator < m_denominator) ? m_numerator : m_denominator;;
	}

	void Fraction::reduce()
	{
		int divisor = gcd();
		m_numerator = m_numerator / divisor;
		m_denominator = m_denominator / divisor;
	}

	int Fraction::gcd() const {
		int mn = min();  // min of numerator and denominator
		int mx = max();  // max of numerator and denominator
		int g_c_d = 1;
		bool found = false;

		for (int x = mn; !found && x > 0; --x) { // from mn decrement until divisor found
			if (mx % x == 0 && mn % x == 0) {
				found = true;
				g_c_d = x;
			}
		}
		return g_c_d;
	}
	//Public Members
	bool Fraction::isEmpty() const
	{
		return (m_numerator < 0 && m_denominator <= 0) ? true : false;
	}

	void Fraction::display() const
	{
		if (isEmpty())
		{
			cout << "no fraction stored";
		}
		else if (m_denominator != 1)
		{
			cout << m_numerator << "/" << m_denominator;
		}
		else
		{
			cout << m_numerator;
		}
	}

	Fraction Fraction::operator+(const Fraction & rhs) const
	{
		Fraction value; 
		if (isEmpty() || rhs.isEmpty())
		{
			//Return value, which will be in a safe empty state
		}
		else
		{
			value.m_numerator = (this->m_numerator * rhs.m_denominator) + (this->m_denominator * rhs.m_numerator);
			value.m_denominator = this->m_denominator * rhs.m_denominator;
			value.reduce();
		}

		return value;
	}
}