#include "Dog.hpp"

Dog::Dog()
{
	std::cout << "Dog constructor launched." << std::endl;
	type = "Dog";
}

Dog::Dog(const Dog& d)
	: Animal(d)
{
	std::cout << "Dog copy constructor launched." << std::endl;
}

Dog&	Dog::operator=(const Dog& d)
{
	std::cout << "Dog copy assignment launched." << std::endl;
	type = d.type;
	return *this;
}

Dog::~Dog()
{
	std::cout << "Dog destructor launched." << std::endl;
}

void	Dog::makeSound() const
{
	std::cout << "Woof" << std::endl;
}
