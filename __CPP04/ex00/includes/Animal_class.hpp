/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal_class.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychibani <ychibani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 11:15:03 by ychibani          #+#    #+#             */
/*   Updated: 2023/01/03 15:51:39 by ychibani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __ANIMAL_CLASS_HPP__
# define __ANIMAL_CLASS_HPP__

#include "includes.hpp"

class Animal
{
	public :
		Animal(void);
		Animal(const Animal &);
		Animal(const std::string &animal);
		virtual	~Animal(void);
		Animal &operator=(const Animal &);

		void		setType(std::string);
		std::string	getType(void) const;
		virtual void		makeSound(void) const;

	protected :
		std::string	type;
		/* data */
};

#endif