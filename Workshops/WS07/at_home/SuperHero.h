#ifndef SICT_SUPERHERO_H
#define SICT_SUPERHERO_H

#include "Hero.h"

namespace sict
{
	class SuperHero : public Hero
	{
		int m_bonus;
		int m_def;
	public:
		SuperHero();
		SuperHero(const char* name, int health, int atkstr, int bonus, int def);
		~SuperHero();
		int attackStrength() const;
		int defend() const;
	};

	const SuperHero& operator*(const SuperHero& first, const SuperHero& second);
}
#endif //SICT_SUPERHERO_H
