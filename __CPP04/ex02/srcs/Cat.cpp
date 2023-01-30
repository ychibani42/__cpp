/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychibani <ychibani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 13:07:16 by ychibani          #+#    #+#             */
/*   Updated: 2023/01/17 18:47:57 by ychibani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void) : Animal("Cat")
{
	this->_Brain = new Brain();
	std::cout << "[Cat default constructor called]" << std::endl;
}

Cat::~Cat(void)
{
	std::cout << "[Cat destructor called]" << std::endl;
	delete this->_Brain;
}

Cat::Cat(Cat &to_assign)
{
	std::cout << "[Cat copy constructor called]" << std::endl;
	this->_Brain = new Brain();
	*this = to_assign;
}

void	Cat::set_idea(int index, std::string new_idea)
{
	this->_Brain->set_idea(index, new_idea);
}

std::string Cat::get_idea(int index)
{
	return (this->_Brain->get_idea(index));
}

Cat &Cat::operator=(const Cat &cpy)
{
	this->type = cpy.type;
	std::cout << "[Cat assignement operator overload called]" << std::endl;
	return (*this);
}

void	Cat::makeSound(void) const
{
	std::cout << "*meeooow*			(ﾐΦ ﻌ Φﾐ)ﾉ" << std::endl;
}
