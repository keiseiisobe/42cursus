#include "Zombie.hpp"

Zombie	*newZombie(std::string name)
{
	class Zombie	*z = new Zombie(name);

	return (z);
}
