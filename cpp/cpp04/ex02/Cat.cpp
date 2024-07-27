#include "Cat.hpp"

Cat::Cat()
{
	type = "Cat";
	b = new Brain();
}

Cat::Cat(const Cat& c)
	: Animal(c)
{
}

Cat&	Cat::operator=(const Cat& c)
{
	type = c.type;
	return *this;
}

Cat::~Cat()
{
	delete b;
}

void	Cat::makeSound() const
{
	std::cout << "Meows" << std::endl;
}
