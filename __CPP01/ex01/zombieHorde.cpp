/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychibani <ychibani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 13:43:12 by ychibani          #+#    #+#             */
/*   Updated: 2022/12/22 14:13:19 by ychibani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
	Zombie *newZombies;

	newZombies = new Zombie[N];
	for(int i = 0; i < N; i++)
		newZombies[i].set_name(name);
	return (newZombies);
}