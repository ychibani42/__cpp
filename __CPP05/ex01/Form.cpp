/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychibani <ychibani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 13:31:46 by ychibani          #+#    #+#             */
/*   Updated: 2023/01/12 15:07:35 by ychibani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : __name("No name"), __is_signed(false), __rqrd_sgnd_grd(1), __rqrd_xct_grd(1) {}
Form::Form(const Form &cpy){*this = cpy;}

Form::Form(const std::string name, bool is_signed, unsigned int rqrd_sgnd_grd, unsigned int rqrd_xct_grd) : __name(name), __rqrd_sgnd_grd(rqrd_sgnd_grd), __rqrd_xct_grd(rqrd_xct_grd)
{
	std::cout << "[Form complete constructor called]" << std::endl;
	if (rqrd_sgnd_grd < 1 || rqrd_xct_grd < 1)
		throw (Form::GradeTooHighException());
	else if (rqrd_sgnd_grd > 150 || rqrd_xct_grd > 150)
		throw (Form::GradeTooLowException());
	else
		this->__is_signed = false;
}

Form &Form::operator=(const Form &rhs)
{
	std::cout << "[Form complete constructor called]" << std::endl;
	this->__is_signed = rhs.__is_signed;
	return *this;
}

void	Form::beSigned(Bureaucrat &newBrct)
{
	if (this->__is_signed)
		std::cout << " already sign" << std::endl;
	else if (newBrct.get_rank() <= this->__rqrd_sgnd_grd)
	{
		std::cout << newBrct.get_name() << " signed " << this->__name << std::endl;
		__is_signed = true;	
	}
	else
		throw (Form::GradeTooLowException());
}

std::ostream &operator<<(std::ostream &os, Form &frm)
{
	os << frm;
	return (os);
}

const char *Form::GradeTooLowException()
{
	return ("Grade too low");
}

const char *Form::GradeTooHighException()
{
	return ("Grade too high");
}