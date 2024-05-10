#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	fixed_point_num = 0;
}

Fixed::Fixed(const int i_num)
{
	// handle overflow
	std::cout << "Int constructor called" << std::endl;
	setRawBits(i_num * std::pow(2, 8));
}

Fixed::Fixed(const float f_num)
{
	std::cout << "Float constructor called" << std::endl;
	setRawBits(roundf(f_num * std::pow(2, 8)));
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
//	std::cout << "getRawBits member function called" << std::endl;
	return fixed_point_num;
}

void	Fixed::setRawBits(int const raw)
{
//	std::cout << "setRawBits member function called" << std::endl;
	fixed_point_num = raw;
}

int	Fixed::toInt(void) const
{
	return (getRawBits() * pow(2, -8)); // forbidden function ?
}

float	Fixed::toFloat(void) const
{
	return (getRawBits() * pow(2, -8));
}
