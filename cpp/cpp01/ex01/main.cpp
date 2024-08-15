#include "Zombie.hpp"

int	main()
{
	try
	{
		std::string	name = "John";
		int			N = 5;
		class Zombie	*z = zombieHorde(N, name);

		for (int i = 0; i < N; i++)
			z[i].announce();
		delete[] z;
	}
	catch (std::bad_alloc&)
	{
		std::cout << "Memory exhausted!" << std::endl;
		return 1;
	}
	return 0;
}

/* __attribute__((destructor)) */
/* static void destructor() { */
/*     system("leaks -q Moar_brainz!"); */
/* } */
