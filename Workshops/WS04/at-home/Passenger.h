#ifndef SICT_PASSENGER_H
#define SICT_PASSENGER_H

namespace sict
{
	class Passenger
	{
	public:
		Passenger();
		Passenger(const char* name,const char* dest);
		~Passenger();
		bool isEmpty() const;
		void display() const;

	private:
		char m_name[32];
		char m_dest[32];
	};
}
#endif // !SICT_PASSENGER_H


