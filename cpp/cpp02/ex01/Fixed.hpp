#ifndef FIXED_HPP
#define FIXED_HPP

#include <string>
#include <iostream>
#include <cmath>

class	Fixed
{
	private:
		int					fixed_point_num;
		static const int	num_of_bits = 8;
	public:
		Fixed();
		Fixed(const int i_num);
		Fixed(const float f_num);
		Fixed(const Fixed&);
		Fixed&	operator=(const Fixed&);
		~Fixed();
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		int		toInt(void) const;
		float	toFloat(void) const;
		void	print(void) const;
};

std::ostream&	operator<<(std::ostream&, const Fixed&);

#endif
