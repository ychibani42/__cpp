/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychibani <ychibani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 13:07:16 by ychibani          #+#    #+#             */
/*   Updated: 2023/01/05 14:15:53 by ychibani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat_class.hpp"

Cat::Cat(void) : Animal("Cat")
{
	std::cout << "[Cat default constructor called]" << std::endl;
}

Cat::~Cat(void)
{
	std::cout << "[Cat destructor called]" << std::endl;
}

Cat::Cat(Cat &to_assign)
{
	std::cout << "[Cat copy constructor called]" << std::endl;
	*this = to_assign;
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
