/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychibani <ychibani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 17:53:47 by ychibani          #+#    #+#             */
/*   Updated: 2023/01/15 18:07:00 by ychibani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string target) :
	Form("PresidentialPardonForm", 25, 5), _target(target){}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &src) :
	Form(src), _target(src._target){}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &rhs)
{
	_target = rhs._target;
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm(){}

void	PresidentialPardonForm::execute(Bureaucrat const &newBureau) const
{
	std::cout << _target << " has been pardoned by Zafod Beeblebrox." << std::endl;
}