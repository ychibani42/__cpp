/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychibani <ychibani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 13:47:38 by ychibani          #+#    #+#             */
/*   Updated: 2022/12/31 20:57:16 by ychibani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) : __HitPoints(10), __EnergyPoints(10), __AttackDamage(0)
{
	std::cout << "[default constructor]" << std::endl;
}

ClapTrap::ClapTrap(const std::string &name) : __name((std::string &)name), __HitPoints(10), __EnergyPoints(10), __AttackDamage(0) {
	std::cout << "[copy constructor]" << std::endl;
}

ClapTrap::ClapTrap (const std::string &__name, const int pv, const int mana, const int ad) : __name(__name), __HitPoints(pv), __EnergyPoints(mana), __AttackDamage(ad){}

ClapTrap::ClapTrap(const ClapTrap &ref){*this = ref;}

ClapTrap::~ClapTrap(void){
	std::cout << "[destructor called]" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &ref)
{
	std::cout << "[assignment overload]" << std::endl;
	this->__name = ref.__name;
	this->__HitPoints = ref.__HitPoints;
	this->__EnergyPoints = ref.__EnergyPoints;
	this->__AttackDamage = ref.__AttackDamage;
	return (*this);
}

void	ClapTrap::attack(const std::string& target)
{
	if (this->get_hitpoint() <= 0)
		std::cout << this->__name << ": Is dead !.." << std::endl;
	else if ( this->get_energypoint() <= 0)
		std::cout << this->__name << " is out of energy" << std::endl;
	else
	{
		std::cout << "Claptrap " << this->__name << " attacks " << target << ", causing " << this->__AttackDamage << " points of damage !" << std::endl;
		this->__EnergyPoints -= 1;
	}
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (amount <= 0)
		std::cout << "put more damages pls" << std::endl;
	else if (this->__HitPoints <= 0)
		std::cout << "can't attack a dead body.." << std::endl;
	else
	{
		if (this->get_hitpoint() - (int)amount <= 0)
			amount = this->get_hitpoint();
		this->__HitPoints -= amount;
		if (this->__HitPoints <= 0)
			std::cout << this->__name << " died in atrocious suffering" << std::endl;
		else
			std::cout << this->__name << " lost " << amount << " points of damage ! " << this->__HitPoints << " left"<< std::endl;
	}
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (!amount)
		std::cout << this->__name << "can't repair 0 energy" << std::endl;
	else if (this->__HitPoints <= 0)
		std::cout << "can't repair a dead body" << std::endl;
	else if (this->__EnergyPoints <= 0)
		std::cout << this->__name << " is out of energy" << std::endl;
	else
	{
		this->__HitPoints += amount;
		std::cout << "ClapTrap " << this->get_name() << " has been repaired of " << amount << " hit points!" << std::endl;
	}
}

int	ClapTrap::get_damage(void) { return (this->__AttackDamage); }
std::string	ClapTrap::get_name(void) { return (this->__name); }
int	ClapTrap::get_hitpoint(void) { return (this->__HitPoints); }
int	ClapTrap::get_energypoint(void) { return (this->__EnergyPoints); }