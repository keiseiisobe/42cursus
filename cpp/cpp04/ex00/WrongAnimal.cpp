#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
	: type("")
{
	std::cout << "WrongAnimal constructor launched." << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& a)
	: type(a.type)
{
	std::cout << "WrongAnimal copy constructor launched." << std::endl;
}

WrongAnimal&	WrongAnimal::operator=(const WrongAnimal& a)
{
	std::cout << "WrongAnimal copy assignment launched." << std::endl;
	type = a.type;
	return *this;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal destructor launched." << std::endl;
}

std::string	WrongAnimal::get_type() const
{
	return type;
}

void	WrongAnimal::makeSound() const
{
	std::cout << "AAAnimalllll...." << std::endl;
}
