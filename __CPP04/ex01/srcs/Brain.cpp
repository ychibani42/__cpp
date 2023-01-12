/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychibani <ychibani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 12:42:53 by ychibani          #+#    #+#             */
/*   Updated: 2023/01/05 15:02:02 by ychibani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain (void){}

Brain::Brain(const Brain &cpy)
{
	*this = cpy;
}

Brain Brain::operator=(const Brain &to_assign)
{
	if (this == &to_assign)	
		return (*this);
	for (int i = 0; i < __MAX_IDEAS; i++)
		this->Ideas[i] = to_assign.Ideas[i];
	return (*this);
}

std::string Brain::get_idea(int index)
{
	if (index >= __MAX_IDEAS || index < 0)
	{
		std::cout << "can't get this idea" << std::endl;
		return ("this idea doesn't exist");
	}
	return (this->Ideas[index]);
}

void Brain::set_idea(int index, std::string new_idea)
{
	if (index >= __MAX_IDEAS || index < 0)
	{
		std::cout << "can't add this idea" << std::endl;
		return ;
	}
	this->Ideas[index] = new_idea;
}

Brain::~Brain (void){}