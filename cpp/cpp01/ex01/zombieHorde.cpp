#include "Zombie.hpp"

Zombie*	zombieHorde(int N, std::string name)
{
	class Zombie	*z = new Zombie[N]();

	for (int i = 0; i < N; i++)
		z[i].put_name(name);
	return (z);
}
