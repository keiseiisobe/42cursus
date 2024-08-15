#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class	WrongCat : public WrongAnimal
{
	public:
		WrongCat();
		WrongCat(const WrongCat& d);
		WrongCat&	operator=(const WrongCat& d);
		~WrongCat();
		void	makeSound() const;
};

#endif
