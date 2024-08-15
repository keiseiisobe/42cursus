#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain constructor launched" << std::endl;
}

Brain::Brain(const Brain& b)
{
	std::cout << "Brain copy constructor launched" << std::endl;
	for (int i = 0;i < size;i++)
		ideas[i] = b.ideas[i];
}

Brain&	Brain::operator=(const Brain& b)
{
	std::cout << "Brain copy assignment launched" << std::endl;
	for (int i = 0;i < size;i++)
		ideas[i] = b.ideas[i];
	return *this;
}

Brain::~Brain()
{
	std::cout << "Brain destructor launched" << std::endl;
}
