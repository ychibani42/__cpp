/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychibani <ychibani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 18:21:03 by ychibani          #+#    #+#             */
/*   Updated: 2022/12/22 11:31:35 by ychibani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class Zombie
{
	public:
		Zombie(void);
		Zombie(std::string name);
		~Zombie(void);

		std::string	get_name(void);
		void		set_name(std::string name);
		void		announce( void );
		// 

	private:
		std::string __name;
	// 
};


Zombie* newZombie( std::string name );
void	randomChump( std::string name );