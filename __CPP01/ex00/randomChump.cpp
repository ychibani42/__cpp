/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychibani <ychibani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 19:10:32 by ychibani          #+#    #+#             */
/*   Updated: 2022/12/22 12:13:02 by ychibani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

void	randomChump( std::string name )
{
	Zombie newZombie;
	
	newZombie.set_name(name);
	newZombie.announce();
	// std::cout << newZombie.get_name() << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie* newZombie(std::string name)
{
	Zombie *newZombie(0);

	newZombie = new Zombie(name);
	
	return (newZombie);
}