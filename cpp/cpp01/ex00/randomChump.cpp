#include "Zombie.hpp"

void	randomChump(std::string name)
{
	class Zombie	z(name);

	z.announce();
}
