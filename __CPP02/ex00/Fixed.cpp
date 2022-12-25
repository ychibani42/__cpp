#include "Fixed.hpp"

Fixed::Fixed(void) : __fixed_value(0)
{
    std::cout << "Default Construtor Called" << std::endl;
}

Fixed::~Fixed(void)
{
    std::cout << "Destructor Called" << std::endl;
}

Fixed::Fixed(Fixed &t)
{
    std::cout << "Copy Constructor Called" << std::endl;
    this->__fixed_value = t.getRawBits();
}

int Fixed::getRawBits( void ) const
{
    std::cout << "getRawBits member function called" << std::endl;
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
    return *this;
}