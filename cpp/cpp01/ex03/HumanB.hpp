#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"

class HumanB
{
	private:
		std::string		name;
		class Weapon	*w;
	public:
		HumanB(std::string init_name);
		~HumanB();
		void	setWeapon(class Weapon& init_w);
		void	attack(void);
};

#endif
