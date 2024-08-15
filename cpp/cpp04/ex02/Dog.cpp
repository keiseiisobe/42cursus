#include "Dog.hpp"

Dog::Dog()
{
	std::cout << "Dog constructor launched" << std::endl;
	type = "Dog";
	b = new Brain();
}

Dog::Dog(const Dog& d)
	: Animal(d)
{
	std::cout << "Dog copy constructor launched" << std::endl;
	b = new Brain(*d.b);
}

Dog&	Dog::operator=(const Dog& d)
{
	std::cout << "Dog copy assignment launched" << std::endl;
	type = d.type;
	*b = *d.b;
	return *this;
}

Dog::~Dog()
{
	std::cout << "Dog destructor launched" << std::endl;
	delete b;
}

void	Dog::makeSound() const
{
	std::cout << "Woof" << std::endl;
}
