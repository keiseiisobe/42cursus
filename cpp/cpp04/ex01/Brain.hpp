#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

class	Brain
{
	private:
		static const int	size = 100;
	public:
		std::string			ideas[size];
		Brain();
		Brain(const Brain&);
		Brain&	operator=(const Brain&);
		~Brain();
};

#endif
