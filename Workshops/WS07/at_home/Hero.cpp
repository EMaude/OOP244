#include "Hero.h"

using namespace std;
namespace sict
{
	Hero::Hero()
	{
		strcpy(m_name, " ");
		m_health = 0;
		m_atkstr = 0;
	}
	Hero::Hero(const char* name,int health,int atkstr)
	{
		if (name != nullptr && strlen(name) < 40 && health > 0 && atkstr > 0)
		{
			strcpy(m_name, name);
			m_health = health;
			m_atkstr = atkstr;
		}
		else
		{
			*this = Hero();
		}
	}
	Hero::~Hero()
	{
	}
	void Hero::operator-=(int attack)
	{
		if (attack > 0)
		{
			if (m_health <= attack)
			{
				m_health = 0;
			}
			else
			{
				m_health -= attack;
			}
		}
	}
	bool Hero::isAlive() const
	{
		return (m_health > 0)? true : false;
	}
	int Hero::attackStrength() const
	{
		return m_atkstr;
	}
	std::ostream &operator<<(std::ostream & os, const Hero& hero)
	{
		if (strcmp(hero.m_name, " ") == 0)
		{
			os << "No Hero";
		}
		else
		{
			os << hero.m_name;
		}
		
		return os;
	}
	const Hero &operator*(const Hero& first, const Hero& second)
	{
		Hero one, two, winner;

		one = first;
		two = second;

		int i = 0;
		while(one.isAlive() && two.isAlive() && i < maxrounds)
		{
			one -= two.attackStrength();
			two -= one.attackStrength();
			i++;
		}

		winner = (!one.isAlive()) ? two : one;

		cout << "Ancient Battle! " << one << " vs " << two << " : " << "Winner is " << winner << " in " << i << " rounds." << endl;

		return (!one.isAlive()) ? second : first;
	}
}