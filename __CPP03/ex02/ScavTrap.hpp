/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychibani <ychibani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 18:22:43 by ychibani          #+#    #+#             */
/*   Updated: 2023/01/03 09:52:06 by ychibani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __SCAVTRAP_HPP__
# define __SCAVTRAP_HPP__

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	public: 
		ScavTrap (void);
		ScavTrap (const ScavTrap&);
		ScavTrap (const std::string&);
		~ScavTrap (void);

		ScavTrap& 	operator=(const ScavTrap&);

		void		guardGate (void);
		void		attack (const std::string&);
};

#endif