#include "Dog.hpp"

Dog::Dog()
{
	type = "Dog";
	b = new Brain();
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
	delete b;
}

void	Dog::makeSound() const
{
	std::cout << "Woof" << std::endl;
}
