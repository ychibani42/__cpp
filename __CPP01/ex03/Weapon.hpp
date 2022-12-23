/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychibani <ychibani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 14:58:47 by ychibani          #+#    #+#             */
/*   Updated: 2022/12/22 21:01:28 by ychibani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#ifndef __WEAPON_HPP__
# define __WEAPON_HPP__

class Weapon
{
	public:
		Weapon(void);
		Weapon(std::string weapon_type);
		~Weapon(void);
		void		setType(std::string weapon);
		std::string	getType( void );
	
	private:
		std::string __weapon_name;
};

#endif