#include "Zombie.hpp"

Zombie::Zombie(std::string init_name)
{
	name = init_name;
}

Zombie::~Zombie()
{
	std::cout << name << ": Finally time to dieeeee..." << std::endl;
}

void	Zombie::announce(void)
{
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
