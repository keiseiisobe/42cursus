#include "Animal.hpp"

Animal::Animal()
	: type("")
{
}

Animal::Animal(const Animal& a)
	: type(a.get_type())
{
}

Animal&	Animal::operator=(const Animal& a)
{
	type = a.get_type();
	return *this;
}

Animal::~Animal()
{
}

std::string	Animal::get_type() const
{
	return type;
}

void	Animal::set_type(const std::string new_type)
{
	type = new_type;
}

void	Animal::makeSound() const
{
}
