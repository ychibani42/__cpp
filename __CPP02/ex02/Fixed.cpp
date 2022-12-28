/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychibani <ychibani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 13:29:07 by ychibani          #+#    #+#             */
/*   Updated: 2022/12/27 19:52:13 by ychibani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"


Fixed::Fixed(void) : __fixed_value(0){}

Fixed::~Fixed(void){ };

Fixed::Fixed(const Fixed &t){*this = t;}

/*
**		To convert from floating-point to fixed-point, we follow this algorithm:
**		Calculate x = floating_input * 2^(fractional_bits)
**		Round x to the nearest whole number (e.g. round(x))
*/

Fixed::Fixed(int const i) : __fixed_value(i * (1 << Fixed::__fract_part)){};

Fixed::Fixed(const float f) : __fixed_value((int)roundf(f * (1 << Fixed::__fract_part))){};

int Fixed::getRawBits( void ) const{return (this->__fixed_value);}

void  Fixed::setRawBits(int const raw)
{
    this->__fixed_value = raw;
}

/*
**
**				C++ OPERATORS
**
*/

Fixed &Fixed::operator=(const Fixed &newFixed)
{
    if (this != &newFixed)
        this->__fixed_value = newFixed.getRawBits();
    return (*this);
}

int			Fixed::operator==(const Fixed &to_cmp){ return (this->__fixed_value == to_cmp.getRawBits()); }
int			Fixed::operator!=(const Fixed &to_cmp){ return (this->__fixed_value != to_cmp.getRawBits()); }
int			Fixed::operator<=(const Fixed &to_cmp){ return (this->__fixed_value <= to_cmp.getRawBits()); }
int			Fixed::operator>=(const Fixed &to_cmp){ return (this->__fixed_value >= to_cmp.getRawBits()); }
int			Fixed::operator>(const Fixed &to_cmp){ return (this->__fixed_value > to_cmp.getRawBits()); }
int			Fixed::operator<(const Fixed &to_cmp){ return (this->__fixed_value < to_cmp.getRawBits()); }
Fixed		Fixed::operator+(const Fixed &to_add){ return(Fixed(this->toFloat() + to_add.toFloat())); }
Fixed		Fixed::operator-(const Fixed &to_add){ return(Fixed(this->toFloat() - to_add.toFloat())); }
Fixed		Fixed::operator*(const Fixed &to_add){ return(Fixed(this->toFloat() * to_add.toFloat())); }
Fixed		Fixed::operator/(const Fixed &to_add){ return(Fixed(this->toFloat() / to_add.toFloat())); }

Fixed		&Fixed::operator++()
{
	this->__fixed_value += 1;
	return (*this);
}

Fixed		&Fixed::operator--()
{
	this->__fixed_value -= 1;
	return (*this);
}

Fixed		Fixed::operator++(int)
{
	Fixed	post(*this);
	this->__fixed_value += 1;
	return (post);
}

Fixed		Fixed::operator--(int)
{
	Fixed	post(*this);
	this->__fixed_value -= 1;
	return (post);
}

/*Fixed		Fixed::operator+(const Fixed &to_add)
{
	Fixed A;

	A.setRawBits(this->__fixed_value + to_add.getRawBits());
	return (A);
}*/

std::ostream& operator<<(std::ostream& os, const Fixed &newFixed)
{
	os << newFixed.toFloat();
    return (os);
}

/*
**
**				MEMBER FONCTIONS
**
*/

float	Fixed::toFloat(void) const
{
	return ((float)this->__fixed_value / (1 << Fixed::__fract_part));
}

int	Fixed::toInt(void) const
{
	return ((int)this->__fixed_value / (1 << Fixed::__fract_part));
}

Fixed&	Fixed::min(Fixed& a, Fixed&	b)
{
	if (a < b)
		return (a);
	return (b);
}

Fixed&	Fixed::max(Fixed& a, Fixed& b)
{
	if (a < b)
		return (b);
	return (a);
}

const Fixed&	Fixed::min(const Fixed& a, const Fixed& b)
{
	if (a.getRawBits() < b.getRawBits())
		return (a);
	return (b);
}

const Fixed&	Fixed::max(const Fixed& a,const Fixed& b)
{
	if (a.getRawBits() < b.getRawBits())
		return (b);
	return (a);
}