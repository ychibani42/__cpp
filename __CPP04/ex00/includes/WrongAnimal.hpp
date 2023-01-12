/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychibani <ychibani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 11:15:03 by ychibani          #+#    #+#             */
/*   Updated: 2023/01/05 12:32:15 by ychibani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __WRONGANIMAL_HPP__
# define __WRONGANIMAL_HPP__

#include "includes.hpp"

class WrongAnimal
{
	public :
		WrongAnimal(void);
		WrongAnimal(const WrongAnimal &);
		WrongAnimal(const std::string &animal);
		virtual ~WrongAnimal(void);
		WrongAnimal &operator=(const WrongAnimal &);

		void		setType(std::string);
		std::string	getType(void) const;
		void		makeSound(void) const;

	protected :
		std::string	type;
		/* data */
};

#endif