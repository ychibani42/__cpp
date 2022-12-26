/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychibani <ychibani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 13:53:35 by ychibani          #+#    #+#             */
/*   Updated: 2022/12/22 13:59:20 by ychibani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(void)
{
	return ;
}

Zombie::~Zombie(void)
{
	return ;
}

void	Zombie::set_name(std::string name)
{
	this->_name = name;
}

std::string &Zombie::get_name(void)
{
	return (this->_name);
}

void	Zombie::announce(void)
{
	std::cout << this->_name << ":	BraiiiiiiinnnzzzZ..." << std::endl;
}