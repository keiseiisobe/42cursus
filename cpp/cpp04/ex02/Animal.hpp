#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class	Animal
{
	protected:
		std::string	type;
	public:
		virtual ~Animal();
		std::string	get_type() const;
		virtual void		makeSound() const = 0;
};

#endif
