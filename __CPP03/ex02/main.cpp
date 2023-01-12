/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychibani <ychibani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 13:47:33 by ychibani          #+#    #+#             */
/*   Updated: 2023/01/03 10:37:05 by ychibani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int	main( void )
{
	{
		ScavTrap sc4vtp("sc4vtp");

		sc4vtp.attack("Handsome Jack");
		sc4vtp.takeDamage(6);
		sc4vtp.beRepaired(4);
		sc4vtp.takeDamage(3);
		sc4vtp.guardGate();
		sc4vtp.beRepaired(8);
		sc4vtp.takeDamage(17);
		sc4vtp.takeDamage(86);
		sc4vtp.takeDamage(86);
		sc4vtp.beRepaired(8);
		sc4vtp.attack("Handsome Jack");
	}
	{
		ClapTrap cl4ptp("cl4ptp");

		cl4ptp.attack("Handsome Jack");
		cl4ptp.takeDamage(6);
		cl4ptp.beRepaired(4);
		cl4ptp.takeDamage(3);
		cl4ptp.beRepaired(8);
		cl4ptp.takeDamage(17);
		cl4ptp.takeDamage(17);
		cl4ptp.beRepaired(17);
		cl4ptp.attack("someone");
	}
	{
		FragTrap sc4vtp("fr4gtp");

		sc4vtp.attack("Handsome Jack");
		sc4vtp.takeDamage(6);
		sc4vtp.beRepaired(4);
		sc4vtp.takeDamage(3);
		sc4vtp.beRepaired(8);
		sc4vtp.takeDamage(17);
		sc4vtp.takeDamage(86);
		sc4vtp.takeDamage(86);
		sc4vtp.beRepaired(8);
		sc4vtp.attack("Handsome Jack");
	}
}