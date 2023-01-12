/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychibani <ychibani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 11:00:09 by ychibani          #+#    #+#             */
/*   Updated: 2023/01/05 14:48:39 by ychibani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __DOG_CLASS_HPP__
# define __DOG_CLASS_HPP__

#include "includes.hpp"
#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
	public :
		Dog(void);
		Dog(Dog &); 
		Dog	&operator=(const Dog &);
		virtual ~Dog();
		void	makeSound() const;
		void		set_idea(int index, std::string new_idea);
		std::string get_idea(int index);

	private :
		Brain *_Brain;
};

#endif