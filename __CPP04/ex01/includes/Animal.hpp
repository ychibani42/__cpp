/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychibani <ychibani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 11:15:03 by ychibani          #+#    #+#             */
/*   Updated: 2023/01/17 18:39:53 by ychibani         ###   ########.fr       */
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
		virtual ~Animal(void);
		Animal &operator=(const Animal &);

		void		setType(std::string);
		std::string	getType(void) const;
		void		makeSound(void) const;
		virtual std::string	get_idea(int index);
		virtual void		set_idea(int index, std::string);
	protected :
		std::string	type;
};

#endif