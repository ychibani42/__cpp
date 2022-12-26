/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychibani <ychibani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 19:22:17 by ychibani          #+#    #+#             */
/*   Updated: 2022/12/22 12:13:21 by ychibani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(void)
{
	return ;
}

Zombie::Zombie(std::string name)
{
	this->__name = name;
}

std::string	Zombie::get_name(void)
{
	return (this->__name);
}

void	Zombie::set_name(std::string name)
{
	this->__name = name;
}

void	Zombie::announce(void)
{
	std::cout << this->__name << ":	BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::~Zombie(void)
{
	std::cout << this->__name << ": say to you good bye !" << std::endl;
	return ;
}