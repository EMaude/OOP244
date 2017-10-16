// vacation.h
#ifndef VACATION_H
#define VACATION_H

class Vacation
{
	char* m_destination;
	double m_totalCost;
public:
	void display() const;
	Vacation(const Vacation&); //copy constructor
	Vacation& operator=(const Vacation&); //copy operator
};

#endif // VACATION_H  