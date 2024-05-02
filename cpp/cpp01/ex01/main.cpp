#include "Zombie.hpp"

int	main()
{
	std::string	name = "John";
	int			N = 5;
	class Zombie	*z = zombieHorde(N, name);

	for (int i = 0; i < N; i++)
		z[i].announce();
	delete[] z;
	return 0;
}
