/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychibani <ychibani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 13:08:55 by ychibani          #+#    #+#             */
/*   Updated: 2023/01/03 15:48:50 by ychibani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal_class.hpp"

Animal::Animal(void)
{
	if (DEBUG)
		std::cout << "[Animal constructor called]" << std::endl;

}

Animal::~Animal(void)
{
	if (DEBUG)
		std::cout << "[Animal destructor called]" << std::endl;
	
}

Animal::Animal(const std::string &animal) : type(animal)
{
	if (DEBUG)
		std::cout << "[Animal string constructor called]" << std::endl;
}

Animal::Animal(const Animal &cpy)
{
	if (DEBUG)
		std::cout << "[Animal copy constructor called]" << std::endl;
	*this = cpy;
}

Animal &Animal::operator=(const Animal &to_assign)
{
	this->type = to_assign.type;
	if (DEBUG)
		std::cout << "[Dog assignement operator overload called]" << std::endl;
	return (*this);
}

void	Animal::setType(std::string type)
{
	this->type = type;
}

std::string Animal::getType(void) const
{
	return (this->type);
}

void	Animal::makeSound(void) const
{
	std::cout << "Unknown Animal make's sound" << std::endl;
}