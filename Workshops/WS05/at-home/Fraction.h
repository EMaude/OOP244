#ifndef SICT_FRACTION_H
#define SICT_FRACTION_H

namespace sict
{
	class Fraction {
	public:
		//Constructors
		Fraction();
		Fraction(int numerator, int denominator);
	private:
		//instance variables 
		int m_numerator;
		int m_denominator;
		// member functions
		int max() const;
		int min() const;
		void reduce();
		int gcd() const;

	public:
		//member functions
		bool isEmpty() const;
		void display() const;
		//operator overload
		Fraction operator+(const Fraction& rhs) const;
		Fraction operator*(const Fraction& rhs) const;
		bool operator==(const Fraction& rhs) const;
		bool operator!=(const Fraction& rhs) const;
		Fraction& operator+=(const Fraction& rhs);
	};
}
#endif // !SICT_FRACTION_H