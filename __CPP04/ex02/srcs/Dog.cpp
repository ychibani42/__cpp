/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychibani <ychibani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 11:00:09 by ychibani          #+#    #+#             */
/*   Updated: 2023/01/17 18:48:08 by ychibani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void) : Animal("Dog")
{
	std::cout << "[Dog default constructor called]" << std::endl;
	this->_Brain = new Brain();
}

Dog::~Dog(void)
{
	std::cout << "[Dog default destructor called]" << std::endl;
	delete this->_Brain;
}

Dog::Dog(Dog &to_assign)
{
	std::cout << "[Dog copy constructor called]" << std::endl;
	this->_Brain = new Brain();
	*this = to_assign;
}

void	Dog::set_idea(int index, std::string new_idea)
{
	this->_Brain->set_idea(index, new_idea);
}

std::string Dog::get_idea(int index)
{
	return (this->_Brain->get_idea(index));
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