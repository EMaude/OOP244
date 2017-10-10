#ifndef SICT_PASSENGER_H
#define SICT_PASSENGER_H

namespace sict
{
	class Passenger
	{
	public:
		Passenger();
		Passenger(const char* name,const char* dest);
		Passenger(const char* name, const char* dest, int year, int month, int day);
		~Passenger();
		bool isEmpty() const;
		void display() const;
		const char* name() const;
		bool canTravelWith(const Passenger&) const;

	private:
		char m_name[32];
		char m_dest[32];
		int m_year;
		int m_month;
		int m_day;
	};
}
#endif // !SICT_PASSENGER_H


