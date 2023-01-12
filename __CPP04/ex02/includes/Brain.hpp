/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychibani <ychibani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 12:42:57 by ychibani          #+#    #+#             */
/*   Updated: 2023/01/05 14:04:40 by ychibani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __BRAIN_HPP__
# define __BRAIN_HPP__

#include "includes.hpp"
#define __MAX_IDEAS 100

class Brain
{
	public :
		Brain(void);
		Brain(std::string &);
		Brain(const Brain &);
		Brain operator=(const Brain &);
		~Brain(void);
		
		std::string get_idea(int index);
		void		set_idea(int index, std::string new_idea);
	private :
		std::string Ideas[__MAX_IDEAS];
};

# endif