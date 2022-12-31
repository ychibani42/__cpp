/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychibani <ychibani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 13:47:40 by ychibani          #+#    #+#             */
/*   Updated: 2022/12/31 20:55:13 by ychibani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __CLAPTRAP_HPP__
# define __CLAPTRAP_HPP__

# define __SUCCESS 1
# define __FAILURE 0

# include <iostream>

class ClapTrap
{
	public :
		ClapTrap(void);
		ClapTrap(const std::string &name);
		ClapTrap(const ClapTrap &ref);
		ClapTrap (const std::string &, const int , const int , const int );
		~ClapTrap(void);
		ClapTrap &operator=(const ClapTrap &ref);
		void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);


		int				get_damage(void);
		int				get_hitpoint(void);
		int				get_energypoint(void);
		std::string		get_name(void);

	protected :
		std::string	__name;
		int			__HitPoints;
		int			__EnergyPoints;
		int			__AttackDamage;
};

#endif