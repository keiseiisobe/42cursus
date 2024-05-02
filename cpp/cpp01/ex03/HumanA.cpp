#include "HumanA.hpp"

HumanA::HumanA(std::string init_name, class Weapon& init_w)
{
	name = init_name;
	w = &init_w;
}

HumanA::~HumanA()
{
}

void	HumanA::attack(void)
{
	std::cout << name << " attacks with their " << w->getType() << std::endl;
	return ;
}
