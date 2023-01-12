/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat_Class.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychibani <ychibani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 11:00:09 by ychibani          #+#    #+#             */
/*   Updated: 2023/01/03 18:19:12 by ychibani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __CAT_CLASS_HPP__
# define __CAT_CLASS_HPP__

#include "includes.hpp"
#include "Animal_class.hpp"

class Cat : public Animal
{
	public :
		Cat(void);
		Cat(Cat &); 
		Cat	&operator=(const Cat &);
		virtual ~Cat();
		virtual void	makeSound() const;
};

#endif