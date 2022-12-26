/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychibani <ychibani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 12:16:49 by ychibani          #+#    #+#             */
/*   Updated: 2022/12/22 14:12:35 by ychibani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Zombie.hpp"

int
	main(void)
{
	Zombie *newZombies;

	newZombies = zombieHorde(8, "Richtofen"); 
	for (int i = 0; i < 8; i++)
	{
		std::cout << "   " << i << std::endl;
		newZombies[i].announce();
	}
	delete [] newZombies;
}