#include "HumanB.hpp"

HumanB::HumanB(std::string init_name)
{
	name = init_name;
	w = nullptr;
}

HumanB::~HumanB()
{
}

void	HumanB::setWeapon(class Weapon& init_w)
{
	w = &init_w;
}

void	HumanB::attack(void)
{
	if (!w)
		std::cout << name << " has no weapon yet" << std::endl;
	else
		std::cout << name << " attacks with their " << w->getType() << std::endl;
}
