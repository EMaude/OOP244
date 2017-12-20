//Elliot Maude
//032830127

//Encapsuates data in the formant yyyy/mm/dd.
//Wrapper For iostream

#ifndef SICT_DATE_H
#define SICT_DATE_H

#include <iostream>

namespace sict {
	
	const int NO_ERROR = 0; //--No error - the date is valid
	const int CIN_FAILED = 1; // --istream failed on information entry
	const int YEAR_ERROR = 2; // --Year value is invalid
	const int MON_ERROR = 3; //--Month value is invalid
	const int DAY_ERROR = 4; //--Day value is invalid

	const int min_year = 2000;
	const int max_year = 2030;

	class Date {
	private:
		//Private Members
		int m_year;
		int m_month;
		int m_day;
		int m_comp;
		int m_err;

		//Private Methods
		int mdays(int, int)const; //Returns Number of days in month of year
		void errCode(int errorCode); //Sets the error state

	public:
		//Constructors
		Date();
		Date(int, int, int);
		~Date();
		//operators
		bool operator==(const Date& rhs) const;
		bool operator!=(const Date& rhs) const;
		bool operator<(const Date& rhs) const;
		bool operator>(const Date& rhs) const;
		bool operator<=(const Date& rhs) const;
		bool operator>=(const Date& rhs) const;
		
		//Public Methods

		int errCode() const;
		bool bad() const; //returns if error state is not NoError
		bool isEmpty() const; 
		std::istream& read(std::istream& istr); //Reads date from istream yyyy?mm?dd
		std::ostream& write(std::ostream& ostr) const; //Writes date to ostream yyyy/mm/dd

  };

	//Helper Functions
	std::ostream& operator<<(std::ostream& ostr, const Date&);
	std::istream& operator>>(std::istream& istr, Date&);

}
#endif //SICT_DATE_H