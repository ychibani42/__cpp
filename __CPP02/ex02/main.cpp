/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychibani <ychibani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 13:28:24 by ychibani          #+#    #+#             */
/*   Updated: 2023/01/06 14:36:23 by ychibani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>
#include "Fixed.hpp"

int main( void ) {
	
	Fixed a;
	Fixed const b(10);
	Fixed const c(42.42f);
	Fixed const d(b);

	std::cout << "OPERATOR OVERLOAD \"=\"" << std::endl;

	Fixed test;
	
	std::cout << "Before assignment : " << test << std::endl;
	test = c;
	std::cout << "After assignment : " << test << std::endl;
	

	std::cout << std::endl << "OPERATOR OVERLOAD \">\"" << std::endl;
	std::cout << "is c(~42) bigger than b(10) : " << ((Fixed&)c > b) << std::endl;
	std::cout << "OPERATOR OVERLOAD \"<\"" << std::endl;
	std::cout << "is c(~42) smaller than b(10) : " << ((Fixed&)c < b) << std::endl;
	std::cout << "OPERATOR OVERLOAD \">=\"" << std::endl;
	std::cout << "is c(~42) smaller than or egual to b(10) : " << ((Fixed&)c <= b) << std::endl;
	std::cout << "OPERATOR OVERLOAD \"<=\"" << std::endl;
	std::cout << "is c(~42) bigger than or egual to b(10) : " << ((Fixed&)c >= b) << std::endl;
	std::cout << "OPERATOR OVERLOAD \"==\"" << std::endl;
	std::cout << "is c(~42) equal to b(10) : " << ((Fixed&)c == b) << std::endl;
	std::cout << "OPERATOR OVERLOAD \"!=\"" << std::endl;
	std::cout << "is c(~42) different from b(10) : " << ((Fixed&)c != b) << std::endl;
	std::cout << "OPERATOR OVERLOAD \"+\"" << std::endl;
	std::cout << "c(~42) + b(10) = " << ((Fixed&)c + b) << std::endl;
	std::cout << "OPERATOR OVERLOAD \"-\"" << std::endl;
	std::cout << "c(~42) - b(10) = " << ((Fixed&)c - b) << std::endl;
	std::cout << "OPERATOR OVERLOAD \"*\"" << std::endl;
	std::cout << "c(~42) * b(10) = " << ((Fixed&)c * b) << std::endl;
	std::cout << "OPERATOR OVERLOAD \"/\"" << std::endl;
	std::cout << "c(~42) / b(10) = " << ((Fixed&)c / b) << std::endl;

	std::cout << std::endl << "OPERATOR OVERLOAD \"++\" PRE" << std::endl;

	std::cout << "before incrementation" << std::endl;
	std::cout << test << std::endl;
	std::cout << "during incrementation" << std::endl;
	std::cout << ++test << std::endl;
	std::cout << "after incrementation" << std::endl;
	std::cout << test << std::endl;

	std::cout << std::endl << "OPERATOR OVERLOAD \"--\" PRE" << std::endl;

	std::cout << "before incrementation" << std::endl;
	std::cout << test << std::endl;
	std::cout << "during incrementation" << std::endl;
	std::cout << --test << std::endl;
	std::cout << "after incrementation" << std::endl;
	std::cout << test << std::endl;

	std::cout << std::endl << "OPERATOR OVERLOAD \"++\" POST" << std::endl;

	std::cout << "before incrementation" << std::endl;
	std::cout << test << std::endl;
	std::cout << "during incrementation" << std::endl;
	std::cout << test++ << std::endl;
	std::cout << "after incrementation" << std::endl;
	std::cout << test << std::endl;

	std::cout << std::endl << "OPERATOR OVERLOAD \"--\" POST" << std::endl;

	std::cout << "before incrementation" << std::endl;
	std::cout << test << std::endl;
	std::cout << "during incrementation" << std::endl;
	std::cout << test-- << std::endl;
	std::cout << "after incrementation" << std::endl;
	std::cout << test << std::endl;

	std::cout << std::endl << "MIN FUNCTION" << std::endl;
	std::cout << "min(c, b) = " << Fixed::min(c, b) << std::endl;

	std::cout << std::endl << "MAX FUNCTION" << std::endl;
	std::cout << "min(c, b) = " << Fixed::max(c, b) << std::endl;

	return 0;
}