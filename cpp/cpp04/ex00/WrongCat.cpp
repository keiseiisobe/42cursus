#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	std::cout << "WrongCat constructor launched." << std::endl;
	type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat& d)
	: WrongAnimal(d)
{
	std::cout << "WrongCat copy constructor launched." << std::endl;
}

WrongCat&	WrongCat::operator=(const WrongCat& d)
{
	std::cout << "WrongCat copy assignment launched." << std::endl;
	type = d.type;
	return *this;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat destructor launched." << std::endl;
}

void	WrongCat::makeSound() const
{
	std::cout << "Meows" << std::endl;
}
