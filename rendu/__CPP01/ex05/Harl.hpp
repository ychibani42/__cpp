/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychibani <ychibani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 21:22:24 by ychibani          #+#    #+#             */
/*   Updated: 2022/12/23 22:23:58 by ychibani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __HARL_HPP__
# define __HARL_HPP__

# include <iostream>
# define	__SUCCESS 1

class	Harl
{
	public :
		Harl(void);
		~Harl(void);
		void	complain( std::string level );

	private :
		void	__debug( void );
		void	__info( void );
		void	__warning( void );
		void	__error( void );
};

typedef struct s_lvl
{
	void (Harl::*f)(void);
}	t_lvl;

#endif