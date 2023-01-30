/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*    WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychibani <ychibani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 13:07:16 by ychibani          #+#    #+#             */
/*   Updated: 2023/01/03 18:27:50 by ychibani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(void) : WrongAnimal("WrongCat")
{
	std::cout << "[WrongCat default constructor called]" << std::endl;
}

WrongCat::~WrongCat(void)
{
	std::cout << "[WrongCat destructor called]" << std::endl;
}

WrongCat::WrongCat(const WrongCat &to_assign)
{
	std::cout << "[WrongCat copy constructor called]" << std::endl;
	*this = to_assign;
}

WrongCat &WrongCat::operator=(const WrongCat &cpy)
{
	this->type = cpy.type;
	std::cout << "[WrongCat assignement operator overload called]" << std::endl;
	return (*this);
}

void	WrongCat::makeSound(void) const
{
	std::cout << "*wrong meeooow*			(ﾐΦ ﻌ Φﾐ)ﾉ" << std::endl;
}
