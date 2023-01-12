/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychibani <ychibani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 09:36:27 by ychibani          #+#    #+#             */
/*   Updated: 2023/01/03 10:35:45 by ychibani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "FragTrap.hpp"

FragTrap::FragTrap(void) : ClapTrap(0, 33, 2, 4)
{
	std::cout << "[FragTrap constructor]" << std::endl;
}

FragTrap::FragTrap (const FragTrap &tmp)
{
	std::cout << "[FragTrap copy constructor]" << std::endl;
	*this = tmp;
}

FragTrap::FragTrap (const std::string &name) : ClapTrap(name, 33, 2, 4)
{
	std::cout << "[FragTrap string constructor called]" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &to_assign)
{
	if (&to_assign == this)
		return (*this);
	std::cout << "[FragTrap assignement operator called]" << std::endl;
	*this = to_assign;
	return (*this);
}

void FragTrap::attack(const std::string& attack)
{
	if (this->get_hitpoint() <= 0)
		std::cout << this->get_name() << ": Is dead !.." << std::endl;
	else if ( this->get_energypoint() <= 0)
		std::cout << this->get_name() << " is out of energy" << std::endl;
	else
	{
		std::cout << "FragTrap " << this->get_name() << " attacks " << attack << ", causing " << this->get_damage() << " points of damage !" << std::endl;
		this->__EnergyPoints -= 1;
	}
}

void	highFivesGuys(void)
{
	std::cout << "une demande de high fives sur la sortie standard." << std::endl;
}

FragTrap::~FragTrap(void)
{
	std::cout << "[FragTrap destructor]" << std::endl;
}