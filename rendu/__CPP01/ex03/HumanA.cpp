/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychibani <ychibani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 17:29:31 by ychibani          #+#    #+#             */
/*   Updated: 2022/12/22 21:34:44 by ychibani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "HumanA.hpp"
#include "Weapon.hpp"

// HumanA::HumanA(void)
// {
// 	return ;	
// }

HumanA::HumanA(std::string human_name, Weapon &weapon_type) : __weapon_type(weapon_type), __name(human_name)
{
	return ;	
}

HumanA::~HumanA(void)
{
	return ;	
}

void	HumanA::setWeapon(Weapon &weapon_type)
{
	this->__weapon_type = weapon_type;	
}

Weapon 	HumanA::getWeapon(void)
{
	return (this->__weapon_type);
}

void	HumanA::attack(void)
{
	std::cout << this->__name << " Attack with they're : " << this->__weapon_type.getType() << std::endl;
}