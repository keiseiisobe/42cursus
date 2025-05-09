#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class	Cat : public Animal
{
	private:
		Brain	*b;
	public:
		Cat();
		Cat(const Cat& d);
		Cat&	operator=(const Cat& d);
		~Cat();
		void	makeSound() const;
};

#endif
