#include "Zombie.hpp"

int	main()
{
	std::string	name1 = "John";
	std::string	name2 = "Ken";
	class Zombie	*z;

	randomChump(name1);
	z = newZombie(name2);
	z->announce();
	delete(z);
	return 0;
}
