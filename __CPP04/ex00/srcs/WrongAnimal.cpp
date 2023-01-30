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


WrongAnimal::WrongAnimal (void) : type("unknown")
{
	std::cout << "[WrongAnimal default constructor called]" << std::endl;
	return;
}

WrongAnimal::WrongAnimal (std::string type) : type(type)
{
	std::cout << "[WrongAnimal string constructor called]" << std::endl;
	return;
}

WrongAnimal::WrongAnimal (const WrongAnimal& ref)
{
	std::cout << "[WrongAnimal copy constructor called]" << std::endl;
	*this = ref;
}

WrongAnimal::~WrongAnimal (void)
{
	std::cout << "[WrongAnimal default destructor called]" << std::endl;
	return;
}


WrongAnimal&	WrongAnimal::operator=(const WrongAnimal& ref)
{
	if (this == &ref) {return *this;}
	
	this->type = ref.type;
	return (*this);
}


void WrongAnimal::makeSound(void) const
{
	std::cout << "WrongAnimal make sound" << std::endl;
}

std::string	WrongAnimal::getType(void) const
{
	return (this->type);
}

void	WrongAnimal::setType(std::string type)
{
	this->type = type;
}