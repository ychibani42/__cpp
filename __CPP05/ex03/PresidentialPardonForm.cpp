/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychibani <ychibani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 17:53:47 by ychibani          #+#    #+#             */
/*   Updated: 2023/01/16 12:52:23 by ychibani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string target) :
	Form("PresidentialPardonForm", false, 25, 5), _target(target){}

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
	if (newBureau.get_rank() > this->get_min_rqrd_xct_grd())
		throw (Form::GradeTooLowException());
	else if (this->get_is_signed() == false)
		throw (Form::FormNotSignedException());
	std::cout << _target << " has been pardoned by Zafod Beeblebrox." << std::endl;
}