#pragma once
#ifndef SICT_HERO_H
#define SICT_HERO_H

#include <iostream>
#include <cstring>
namespace sict
{
	const int maxrounds = 100;
	class Hero
	{
	private:
		char m_name[41];
		int m_health;
		int m_atkstr;
	public:
		Hero();
		Hero(const char* name, int health, int atkstr);
		~Hero();
		void operator -=(int attack);
		bool isAlive() const;
		int attackStrength() const;
		friend std::ostream& operator<<(std::ostream& os, const Hero& hero);
	};

	const Hero& operator*(const Hero& first, const Hero& second);
}
#endif //SICT_HERO_H

