#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

class	Brain
{
	public:
		std::string	ideas[100];
		Brain();
		Brain(const Brain&);
		Brain&	operator=(const Brain&);
		~Brain();
};

#endif
