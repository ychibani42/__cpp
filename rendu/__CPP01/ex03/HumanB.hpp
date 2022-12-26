/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychibani <ychibani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 20:39:20 by ychibani          #+#    #+#             */
/*   Updated: 2022/12/22 21:00:36 by ychibani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

class HumanB
{
	public:
		HumanB(void);
		HumanB(std::string name);
		~HumanB(void);
		void	setWeapon (Weapon &weapon_type);
		void	attack(void);

	private:
		Weapon *__weapon_type;
		std::string	__name;
};