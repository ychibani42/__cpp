/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychibani <ychibani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 13:08:55 by ychibani          #+#    #+#             */
/*   Updated: 2023/01/17 17:09:07 by ychibani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal_class.hpp"

Animal::Animal(void) : type("Animal")
{
	std::cout << "[Animal constructor called]" << std::endl;
}

Animal::~Animal(void)
{
	std::cout << "[Animal destructor called]" << std::endl;
}

Animal::Animal(const std::string &animal) : type(animal)
{
	std::cout << "[Animal string constructor called]" << std::endl;
}

Animal::Animal(const Animal &cpy)
{
	std::cout << "[Animal copy constructor called]" << std::endl;
	*this = cpy;
}

Animal &Animal::operator=(const Animal &to_assign)
{
	this->type = to_assign.type;
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