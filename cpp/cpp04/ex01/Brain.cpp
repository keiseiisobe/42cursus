#include "Brain.hpp"

Brain::Brain()
{
}

Brain::Brain(const Brain& b)
{
	for (int i = 0;i < 100;i++)
		ideas[i] = b.ideas[i];
}

Brain&	Brain::operator=(const Brain& b)
{
	for (int i = 0;i < 100;i++)
		ideas[i] = b.ideas[i];
	return *this;
}

Brain::~Brain()
{
}
