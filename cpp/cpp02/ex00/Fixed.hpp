#ifndef FIXED_HPP
#define FIXED_HPP

#include <string>
#include <iostream>

class	Fixed
{
	private:
		int					value;
		static const int	num_of_bits = 8;
	public:
		Fixed();
		Fixed(const Fixed&);
		Fixed&	operator=(const Fixed&);
		~Fixed();
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
};

#endif
