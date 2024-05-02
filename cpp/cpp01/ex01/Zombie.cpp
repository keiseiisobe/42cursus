#include "Zombie.hpp"

Zombie::Zombie()
{
}

Zombie::~Zombie()
{
	std::cout << name << ": Finally time to dieeeee..." << std::endl;
}

void	Zombie::announce(void)
{
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
	return ;
}

void	Zombie::put_name(std::string init_name)
{
	name = init_name;
}
