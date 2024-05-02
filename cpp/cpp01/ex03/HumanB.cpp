#include "HumanB.hpp"

HumanB::HumanB(std::string init_name)
{
	name = init_name;
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
	std::cout << name << " attacks with their " << w->getType() << std::endl;
}
