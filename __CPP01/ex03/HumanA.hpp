/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychibani <ychibani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 14:55:21 by ychibani          #+#    #+#             */
/*   Updated: 2022/12/22 21:34:48 by ychibani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

class HumanA
{
	public :
		// HumanA(void);
		~HumanA(void);
		HumanA(std::string human_name, Weapon &weapon_type);
		void	attack(void);
		void	setWeapon(Weapon &weapon_type);
		Weapon	getWeapon(void);
	private :
		Weapon &__weapon_type;
		std::string __name;
};