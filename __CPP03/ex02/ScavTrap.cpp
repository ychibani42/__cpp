/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychibani <ychibani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 17:54:51 by ychibani          #+#    #+#             */
/*   Updated: 2023/01/03 09:44:25 by ychibani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

ScavTrap::ScavTrap(void) : ClapTrap("", 100, 5, 10)
{
	std::cout << "[ScavTrap constructor called]" << std::endl;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "[ScavTrap destructor called]" << std::endl;
}

ScavTrap::ScavTrap(const std::string &src) : ClapTrap(src, 100, 5, 20)
{
	std::cout << "[string constructor called]" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &tmp) 
{
	std::cout << "[ScavTrap copy constructor called]" << std::endl;
	*this = tmp;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &to_assign)
{
	if (this == &to_assign)
		return (*this);
	std::cout << "[ScavTrap assignement operator called]" << std::endl;
	*this = to_assign;
	return (*this);
}

void ScavTrap::guardGate()
{
	std::cout << "Entering gate keeper mode..." << std::endl;
}

void ScavTrap::attack(const std::string& attack)
{
	if (this->get_hitpoint() <= 0)
		std::cout << this->get_name() << ": Is dead !.." << std::endl;
	else if ( this->get_energypoint() <= 0)
		std::cout << this->get_name() << " is out of energy" << std::endl;
	else
	{
		std::cout << "ScavTrap " << this->get_name() << " attacks " << attack << ", causing " << this->get_damage() << " points of damage !" << std::endl;
		this->__EnergyPoints -= 1;
	}
}