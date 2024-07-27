#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class	Animal
{
	private:
		std::string	type;
	public:
		Animal();
		Animal(const Animal&);
		Animal&	operator=(const Animal&);
		~Animal();
		std::string		get_type() const;
		void			set_type(const std::string new_type);
		virtual void	makeSound() const;
};

#endif
