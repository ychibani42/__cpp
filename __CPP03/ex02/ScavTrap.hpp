/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychibani <ychibani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 18:22:43 by ychibani          #+#    #+#             */
/*   Updated: 2022/12/31 18:22:46 by ychibani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

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