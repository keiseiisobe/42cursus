#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"

class	Cat : public Animal
{
	public:
		Cat();
		Cat(const Cat& d);
		Cat&	operator=(const Cat& d);
		~Cat();
		void	makeSound() const;
};

#endif
