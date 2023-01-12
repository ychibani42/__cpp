/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychibani <ychibani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 11:00:09 by ychibani          #+#    #+#             */
/*   Updated: 2023/01/05 14:48:24 by ychibani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef __CAT_CLASS_HPP__
# define __CAT_CLASS_HPP__

#include "includes.hpp"
#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
	public :
		Cat(void);
		Cat(Cat &); 
		Cat	&operator=(const Cat &);
		virtual ~Cat();
		void		makeSound() const ;
		void		set_idea(int index, std::string new_idea);
		std::string get_idea(int index);

	private :
		Brain *_Brain;
};

#endif