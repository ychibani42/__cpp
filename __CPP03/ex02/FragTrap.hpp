/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychibani <ychibani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 09:51:11 by ychibani          #+#    #+#             */
/*   Updated: 2023/01/03 10:35:07 by ychibani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FRAGTRAP_HPP__
# define __FRAGTRAP_HPP__

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
	public: 
		FragTrap (void);
		FragTrap (const FragTrap&);
		FragTrap (const std::string&);
		~FragTrap (void);

		FragTrap& 	operator=(const FragTrap&);

		void		attack (const std::string&);
		void		highFivesGuys(void);
};

#endif