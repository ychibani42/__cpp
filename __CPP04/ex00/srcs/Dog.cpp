/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychibani <ychibani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 11:00:09 by ychibani          #+#    #+#             */
/*   Updated: 2023/01/17 17:02:14 by ychibani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog_class.hpp"

Dog::Dog(void) : Animal("Dog")
{
	std::cout << "[Dog default constructor called]" << std::endl;
}

Dog::~Dog(void)
{
	std::cout << "[Dog default destructor called]" << std::endl;
}

Dog::Dog(Dog &to_assign)
{
	std::cout << "[Dog copy constructor called]" << std::endl;
	*this = to_assign;
}

Dog &Dog::operator=(const Dog &cpy)
{
	this->type = cpy.type;
	std::cout << "[Dog assignement operator overload called]" << std::endl;
	return (*this);
}

void	Dog::makeSound(void) const
{
	std::cout << "*Bark Bark !*			(υ´• ﻌ •`υ)" << std::endl;
}