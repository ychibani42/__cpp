/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychibani <ychibani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 11:00:09 by ychibani          #+#    #+#             */
/*   Updated: 2023/01/05 12:30:53 by ychibani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __WRONGCAT_CLASS_HPP__
# define __WRONGCAT_CLASS_HPP__

#include "includes.hpp"
#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
	public :
		WrongCat(void);
		WrongCat(WrongCat &); 
		WrongCat	&operator=(const WrongCat &);
		virtual ~WrongCat();
		void	makeSound() const;
};

#endif