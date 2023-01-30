/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychibani <ychibani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 11:49:13 by ychibani          #+#    #+#             */
/*   Updated: 2023/01/16 12:35:40 by ychibani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string target) :
	Form("RobotomyRequestForm", false, 72, 45), _target(target){}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src) :
	Form(src), _target(src._target){}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &rhs)
{
	_target = rhs._target;
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm(){}

void RobotomyRequestForm::execute(Bureaucrat const &newBureau) const
{
	if (newBureau.get_rank() > this->get_min_rqrd_xct_grd())
		throw (Form::GradeTooLowException());
	else if (this->get_is_signed() == false)
		throw (Form::FormNotSignedException());
	else 
	{
		srand(time(NULL));
		if (std::rand() % 2 == 0)
			std::cout << _target << " has been robotomized successfully." << std::endl;
		else
			std::cout << _target << " robotomization failed." << std::endl;
	}
}