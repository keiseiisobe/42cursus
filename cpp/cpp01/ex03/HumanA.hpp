#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"

class HumanA
{
	private:
		std::string		name;
		class Weapon	*w;
	public:
		HumanA(std::string init_name, class Weapon& init_w);
		~HumanA();
		void	attack(void);
};

#endif
