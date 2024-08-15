#include "Cat.hpp"

Cat::Cat()
{
	std::cout << "Cat constructor launched" << std::endl;
	type = "Cat";
	b = new Brain();
}

Cat::Cat(const Cat& c)
	: Animal(c)
{
	std::cout << "Cat copy constructor launched" << std::endl;
	b = new Brain(*c.b);
}

Cat&	Cat::operator=(const Cat& c)
{
	std::cout << "Cat copy assignment launched" << std::endl;
	type = c.type;
	*b = *c.b;
	return *this;
}

Cat::~Cat()
{
	std::cout << "Cat destructor launched" << std::endl;
	delete b;
}

void	Cat::makeSound() const
{
	std::cout << "Meows" << std::endl;
}
