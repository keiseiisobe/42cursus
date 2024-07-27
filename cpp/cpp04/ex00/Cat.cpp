#include "Cat.hpp"

Cat::Cat()
{
	type = "Cat";
}

Cat::Cat(const Cat& d)
	: Animal(d)
{
}

Cat&	Cat::operator=(const Cat& d)
{
	type = d.type;
	return *this;
}

Cat::~Cat()
{
}

void	Cat::makeSound() const
{
	std::cout << "Meows" << std::endl;
}
