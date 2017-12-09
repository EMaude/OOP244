#include "SuperHero.h"

using namespace std;
namespace sict
{
	SuperHero::SuperHero()
	{
		m_bonus = 0;
		m_def = 0;
	}
	SuperHero::SuperHero(const char * name, int health, int atkstr, int bonus, int def) : Hero(name, health, atkstr)
	{
		if (bonus > 0 && def > 0)
		{
			m_bonus = bonus;
			m_def = def;
		}
		else
		{
			m_bonus = 0;
			m_def = 0;
		}
	}
	SuperHero::~SuperHero()
	{
	}
	int SuperHero::attackStrength() const
	{
		return Hero::attackStrength() + m_bonus;
	}
	int SuperHero::defend() const
	{
		return m_def;
	}
	const SuperHero & operator*(const SuperHero & first, const SuperHero & second)
	{
		SuperHero one, two, winner;

		one = first;
		two = second;

		int i = 0;
		while (one.isAlive() && two.isAlive() && i < maxrounds)
		{
			one -= two.attackStrength() - one.defend();
			two -= one.attackStrength() - two.defend();
			i++;
		}

		winner = (!one.isAlive()) ? two : one;

		cout << "Super Fight! " << one << " vs " << two << " : " << "Winner is " << winner << " in " << i << " rounds." << endl;

		return (!one.isAlive()) ? second : first;
	}
}