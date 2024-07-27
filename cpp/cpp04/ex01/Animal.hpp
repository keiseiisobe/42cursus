#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class	Animal
{
	protected:
		std::string	type;
	public:
		Animal();
		Animal(const Animal&);
		Animal&	operator=(const Animal&);
		virtual ~Animal();
		std::string		get_type() const;
		virtual void	makeSound() const;
};

#endif
