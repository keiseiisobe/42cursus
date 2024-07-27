#include "Animal.hpp"

Animal::Animal()
	: type("")
{
}

Animal::Animal(const Animal& a)
	: type(a.type)
{
}

Animal&	Animal::operator=(const Animal& a)
{
	type = a.type;
	return *this;
}

Animal::~Animal()
{
}

std::string	Animal::get_type() const
{
	return type;
}

void	Animal::makeSound() const
{
}
