/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongWrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychibani <ychibani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 13:08:55 by ychibani          #+#    #+#             */
/*   Updated: 2023/01/03 18:22:12 by ychibani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void)
{
	if (DEBUG)
		std::cout << "[WrongAnimal constructor called]" << std::endl;

}

WrongAnimal::~WrongAnimal(void)
{
	if (DEBUG)
		std::cout << "[WrongAnimal destructor called]" << std::endl;
	
}

WrongAnimal::WrongAnimal(const std::string &animal) : type(animal)
{
	if (DEBUG)
		std::cout << "[WrongAnimal string constructor called]" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &cpy)
{
	if (DEBUG)
		std::cout << "[WrongAnimal copy constructor called]" << std::endl;
	*this = cpy;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &to_assign)
{
	this->type = to_assign.type;
	if (DEBUG)
		std::cout << "[Dog assignement operator overload called]" << std::endl;
	return (*this);
}

void	WrongAnimal::setType(std::string type)
{
	this->type = type;
}

std::string WrongAnimal::getType(void) const
{
	return (this->type);
}

void	WrongAnimal::makeSound(void) const
{
	std::cout << "Unknown WrongAnimal make's sound" << std::endl;
}