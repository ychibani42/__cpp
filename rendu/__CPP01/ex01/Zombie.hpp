/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychibani <ychibani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 12:18:09 by ychibani          #+#    #+#             */
/*   Updated: 2022/12/22 13:57:51 by ychibani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class Zombie
{
	public:
		Zombie( void );
		~Zombie( void );

		void		set_name( std::string name );
		std::string	&get_name(void);
		void		announce(void);
	private:
		std::string _name;

};


Zombie* zombieHorde( int N, std::string name );