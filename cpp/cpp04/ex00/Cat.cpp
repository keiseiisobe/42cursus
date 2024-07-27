#include "Cat.hpp"

Cat::Cat()
{
	set_type("Cat");
}

Cat::Cat(const Cat& d)
	: Animal(d)
{
}

Cat&	Cat::operator=(const Cat& d)
{
	set_type(d.get_type());
	return *this;
}

Cat::~Cat()
{
}

void	Cat::makeSound() const
{
	std::cout << "Meows" << std::endl;
}
