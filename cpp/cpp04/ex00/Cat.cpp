#include "Cat.hpp"

Cat::Cat()
{
	std::cout << "Cat constructor launched." << std::endl;
	type = "Cat";
}

Cat::Cat(const Cat& d)
	: Animal(d)
{
	std::cout << "Cat copy constructor launched." << std::endl;
}

Cat&	Cat::operator=(const Cat& d)
{
	std::cout << "Cat copy assignment launched." << std::endl;
	type = d.type;
	return *this;
}

Cat::~Cat()
{
	std::cout << "Cat destructor launched." << std::endl;
}

void	Cat::makeSound() const
{
	std::cout << "Meows" << std::endl;
}
