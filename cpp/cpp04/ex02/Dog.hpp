#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class	Dog : public Animal
{
	private:
		Brain	*b;
	public:
		Dog();
		Dog(const Dog& d);
		Dog&	operator=(const Dog& d);
		~Dog();
		void	makeSound() const;
};

#endif
