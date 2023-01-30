/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychibani <ychibani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 11:00:09 by ychibani          #+#    #+#             */
/*   Updated: 2023/01/17 17:18:25 by ychibani         ###   ########.fr       */
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
		WrongCat(const WrongCat &);
		WrongCat(const std::string &animal);
		virtual ~WrongCat();
		WrongCat	&operator=(const WrongCat &);

		void	makeSound() const;
		void	setType(std::string);
		std::string	getType(void) const;
};

#endif