#include "Fixed.hpp"

Fixed::Fixed()
{
	fixed_point_num = 0;
}

Fixed::Fixed(const int i_num)
{
	int	num = i_num;

	for (int i = 0;i < num_of_bits;i++)
		num *= 2;
	setRawBits(num);
}

Fixed::Fixed(const float f_num)
{
	float	num = f_num;

	for (int i = 0;i < num_of_bits;i++)
		num *= 2;
	setRawBits(roundf(num));
}

Fixed::Fixed(const Fixed& f)
{
	setRawBits(f.getRawBits());
}

Fixed&	Fixed::operator=(const Fixed& f)
{
	setRawBits(f.getRawBits());
	return *this;
}

Fixed::~Fixed()
{
}

// overload operators
bool	Fixed::operator<(const Fixed& f) const
{
	return getRawBits() < f.getRawBits();
}

bool	Fixed::operator>(const Fixed& f) const
{
	return getRawBits() > f.getRawBits();
}

bool	Fixed::operator<=(const Fixed& f) const
{
	return getRawBits() <= f.getRawBits();
}

bool	Fixed::operator>=(const Fixed& f) const
{
	return getRawBits() >= f.getRawBits();
}

bool	Fixed::operator==(const Fixed& f) const
{
	return getRawBits() == f.getRawBits();
}

bool	Fixed::operator!=(const Fixed& f) const
{
	return getRawBits() != f.getRawBits();
}

Fixed	Fixed::operator+(const Fixed& f)
{
	Fixed	tmp(*this);

	tmp.setRawBits(tmp.getRawBits() + f.getRawBits());
	return tmp;
}

Fixed	Fixed::operator-(const Fixed& f)
{
	Fixed	tmp(*this);

	tmp.setRawBits(tmp.getRawBits() - f.getRawBits());
	return tmp;
}

Fixed	Fixed::operator*(const Fixed& f)
{
	Fixed	tmp(*this);
	int		num = tmp.getRawBits() * f.getRawBits();

	for (int i = 0;i < num_of_bits;i++)
		num /= 2;
	tmp.setRawBits(num);
	return tmp;
}

Fixed	Fixed::operator/(const Fixed& f)
{
	Fixed	tmp(*this);
	float	num = tmp.toFloat() / f.toFloat();

	for (int i = 0;i < num_of_bits;i++)
		num *= 2;
	tmp.setRawBits(num);
	return tmp;
}

	// prefix increment
Fixed&	Fixed::operator++()
{
	setRawBits(getRawBits() + 1);
	return *this;
}

	// postfix increment
Fixed	Fixed::operator++(int)
{
	Fixed	tmp;

	tmp = *this;
	setRawBits(getRawBits() + 1);
	return tmp;
}

	// prefix decrement
Fixed&	Fixed::operator--()
{
	setRawBits(getRawBits() - 1);
	return *this;
}

	// postfix decrement
Fixed	Fixed::operator--(int)
{
	Fixed	tmp;

	tmp = *this;
	setRawBits(getRawBits() - 1);
	return tmp;
}

std::ostream&	operator<<(std::ostream&, const Fixed& f)
{
	return std::cout << f.toFloat();
}


// useful member functions
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

Fixed&	Fixed::min(Fixed& a, Fixed& b)
{
	if (a <= b)
		return (a);
	return (b);
}

Fixed&	Fixed::max(Fixed& a, Fixed& b)
{
	if (a >= b)
		return (a);
	return (b);
}

// two functions below must guarantee not to modified parameters, because it has const parameters.
// But, return values (a and b) can be modified after leaving off these functions.
// Then we need to use const_cast not to cause compile error when return not-const values.
Fixed&	Fixed::min(const Fixed& a, const Fixed& b)
{
	if (a <= b)
		return (const_cast<Fixed &>(a));
	return (const_cast<Fixed &>(b));
}

Fixed&	Fixed::max(const Fixed& a, const Fixed& b)
{
	if (a >= b)
		return (const_cast<Fixed &>(a));
	return (const_cast<Fixed &>(b));
}
