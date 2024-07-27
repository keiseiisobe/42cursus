#include "Dog.hpp"

Dog::Dog()
{
	set_type("Dog");
}

Dog::Dog(const Dog& d)
	: Animal(d)
{
}

Dog&	Dog::operator=(const Dog& d)
{
	set_type(d.get_type());
	return *this;
}

Dog::~Dog()
{
}

void	Dog::makeSound() const
{
	std::cout << "Woof" << std::endl;
}
