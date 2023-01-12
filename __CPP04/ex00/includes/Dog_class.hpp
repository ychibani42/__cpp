/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog_class.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychibani <ychibani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 11:00:09 by ychibani          #+#    #+#             */
/*   Updated: 2023/01/03 18:19:48 by ychibani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __DOG_CLASS_HPP__
# define __DOG_CLASS_HPP__

#include "includes.hpp"
#include "Animal_class.hpp"

class Dog : public Animal
{
	public :
		Dog(void);
		Dog(Dog &); 
		Dog	&operator=(const Dog &);
		virtual ~Dog();
		virtual void	makeSound() const;
};

#endif