/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychibani <ychibani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 18:12:21 by ychibani          #+#    #+#             */
/*   Updated: 2022/12/22 12:12:48 by ychibani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

int
	main(void)
{
	Zombie *zombie;

	zombie = newZombie("Yassine");
	zombie->announce();
	delete zombie;

	randomChump("Djenna");
}