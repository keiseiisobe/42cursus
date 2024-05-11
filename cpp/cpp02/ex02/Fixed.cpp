#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	fixed_point_num = 0;
}

Fixed::Fixed(const int i_num)
{
	int	num = i_num;

	std::cout << "Int constructor called" << std::endl;
	for (int i = 0;i < num_of_bits;i++)
		num *= 2;
	setRawBits(num);
}

Fixed::Fixed(const float f_num)
{
	float	num = f_num;

	std::cout << "Float constructor called" << std::endl;
	for (int i = 0;i < num_of_bits;i++)
		num *= 2;
	setRawBits(roundf(num));
}

Fixed::Fixed(const Fixed& f)
{
	std::cout << "Copy constructor called" << std::endl;
	setRawBits(f.getRawBits());
}

Fixed&	Fixed::operator=(const Fixed& f)
{
	std::cout << "Copy assignment operator called" << std::endl;
	setRawBits(f.getRawBits());
	return *this;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int	Fixed::getRawBits(void) const
{
	return fixed_point_num;
}

void	Fixed::setRawBits(int const raw)
{
	fixed_point_num = raw;
}

int	Fixed::toInt(void) const
{
	int	num = getRawBits();

	for (int i = 0;i < num_of_bits;i++)
		num /= 2;
	return (num);
}

float	Fixed::toFloat(void) const
{
	float	num = getRawBits();

	for (int i = 0;i < num_of_bits;i++)
		num /= 2;
	return (num);
}

const Fixed&	Fixed::min(const Fixed& a, const Fixed& b)
{
	if (a.getRawBits() <= b.getRawBits())
		return (a);
	return (b);
}

std::ostream&	operator<<(std::ostream&, const Fixed& f)
{
	return std::cout << f.toFloat();
}
