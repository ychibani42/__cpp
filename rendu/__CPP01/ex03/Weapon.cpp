/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychibani <ychibani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 15:16:07 by ychibani          #+#    #+#             */
/*   Updated: 2022/12/22 21:30:37 by ychibani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include <iostream>

Weapon::Weapon(void)
{
	return ;
}

Weapon::~Weapon(void)
{
	return ;
}

void	Weapon::setType(std::string Weapon)
{
	this->__weapon_name = Weapon;
}

std::string Weapon::getType(void)
{
	return (this->__weapon_name);
}

Weapon::Weapon(std::string weapon_type): __weapon_name(weapon_type)
{
	return ;
}
