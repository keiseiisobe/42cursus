#include "Animal.hpp"

Animal::Animal()
	: type("")
{
	std::cout << "Animal constructor launched" << std::endl;
}

Animal::Animal(const Animal& a)
	: type(a.type)
{
	std::cout << "Animal copy constructor launched" << std::endl;
}

Animal&	Animal::operator=(const Animal& a)
{
	std::cout << "Animal copy assignment launched" << std::endl;
	type = a.type;
	return *this;
}

Animal::~Animal()
{
	std::cout << "Animal destructor launched" << std::endl;
}

std::string	Animal::get_type() const
{
	return type;
}

void	Animal::makeSound() const
{
}
