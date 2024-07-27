#include "Dog.hpp"

Dog::Dog()
{
	type = "Dog";
}

Dog::Dog(const Dog& d)
	: Animal(d)
{
}

Dog&	Dog::operator=(const Dog& d)
{
	type = d.type;
	return *this;
}

Dog::~Dog()
{
}

void	Dog::makeSound() const
{
	std::cout << "Woof" << std::endl;
}
