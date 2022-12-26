#include "Fixed.hpp"


Fixed::Fixed(void) : __fixed_value(0)
{
    std::cout << "Default Construtor Called" << std::endl;
}

Fixed::~Fixed(void)
{
    std::cout << "Destructor Called" << std::endl;
}

Fixed::Fixed(const Fixed &t)
{
    std::cout << "Copy Constructor Called" << std::endl;
    *this = t;
}

/*
**		To convert from floating-point to fixed-point, we follow this algorithm:
**		Calculate x = floating_input * 2^(fractional_bits)
**		Round x to the nearest whole number (e.g. round(x))
*/

Fixed::Fixed(const int i) : __fixed_value(i * (1 << Fixed::__fract_part))
{
    std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float f) : __fixed_value((int)roundf(f * (1 << Fixed::__fract_part)))
{
    std::cout << "Float contructor called" << std::endl;
}

int Fixed::getRawBits( void ) const
{
    return (this->__fixed_value);
}

void  Fixed::setRawBits(int const raw)
{
    this->__fixed_value = raw;
}

Fixed &Fixed::operator=(const Fixed &newFixed)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &newFixed)
        this->__fixed_value = newFixed.getRawBits();
    return (*this);
}

std::ostream& operator<<(std::ostream& os, const Fixed &newFixed)
{
	os << newFixed.toFloat();
    return (os);
}

float	Fixed::toFloat(void) const
{
	return ((float)this->__fixed_value / (1 << Fixed::__fract_part));
}

int	Fixed::toInt(void) const
{
	return ((int)this->__fixed_value / (1 << Fixed::__fract_part));
}