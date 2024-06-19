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

std::ostream&	operator<<(std::ostream&, const Fixed& f)
{
	return std::cout << f.toFloat();
}
/*
void	Fixed::print(void) const
{
	int	integer = fixed_point_num; 
	int	fraction_bits = (fixed_point_num & 0x000000FF);
	int	fraction = 255;

	std::cout << "fixed_point_num: ";
	for (int i = 31;i >= 0;i--)
		std::cout << ((fixed_point_num >> i) & 1);
	std::cout << std::endl;

	for (int i = 0;i < num_of_bits;i++)
		integer /= 2;
	for (int i = 7;i >= 0;i--)
	{
		if ((fraction_bits >> i) & 0x1)
			fraction /= 2;
	}
	std::cout << integer << "." << fraction << std::endl;
}
*/
