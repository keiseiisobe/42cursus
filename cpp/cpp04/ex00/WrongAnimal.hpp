#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>

class	WrongAnimal
{
	protected:
		std::string	type;
	public:
		WrongAnimal();
		WrongAnimal(const WrongAnimal&);
		WrongAnimal&	operator=(const WrongAnimal&);
		~WrongAnimal();
		std::string		get_type() const;
		void	makeSound() const;
};

#endif
