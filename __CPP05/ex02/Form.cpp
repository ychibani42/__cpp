/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychibani <ychibani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 13:31:46 by ychibani          #+#    #+#             */
/*   Updated: 2023/01/15 15:48:12 by ychibani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : __name("No name"), __is_signed(false), __rqrd_sgnd_grd(1), __rqrd_xct_grd(1) {}
Form::Form(const Form &cpy) : __rqrd_sgnd_grd(cpy.__rqrd_sgnd_grd), __rqrd_xct_grd(cpy.__rqrd_xct_grd)
{
	*this = cpy;
}

Form::Form(const std::string name, bool is_signed, unsigned int rqrd_sgnd_grd, unsigned int rqrd_xct_grd) : __name(name), __rqrd_sgnd_grd(rqrd_sgnd_grd), __rqrd_xct_grd(rqrd_xct_grd)
{
	std::cout << "[Form complete constructor called]" << std::endl;
	if (rqrd_sgnd_grd < 1 || rqrd_xct_grd < 1)
		throw (Form::GradeTooHighException());
	else if (rqrd_sgnd_grd > 150 || rqrd_xct_grd > 150)
		throw (Form::GradeTooLowException());
	else
		this->__is_signed = is_signed;
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
		throw std::invalid_argument(" form already signed");
	else if (newBrct.get_rank() <= this->__rqrd_sgnd_grd)
		__is_signed = true;	
	else
		throw (Form::GradeTooLowException());
}

const std::string &Form::getName(void)				 {	return (__name);}
unsigned int Form::get_min_rqrd_sgnd_grd(void) const {	return (__rqrd_sgnd_grd);}
unsigned int Form::get_min_rqrd_xct_grd(void) const  {	return (__rqrd_xct_grd);}
bool Form::get_is_signed(void) const				 {	return (__is_signed);	}

std::ostream &operator<<(std::ostream &os, Form &frm)
{
	os << frm.getName() << ", form grade for execute : " << frm.get_min_rqrd_xct_grd() << " grade required to sign : " << frm.get_min_rqrd_sgnd_grd() << " signed status " << frm.get_is_signed() << std::endl;
	return (os);
}

const char* Form::GradeTooLowException::what() const throw()
{
    return "Grade is too low";
}

const char *Form::GradeTooHighException::what() const throw()
{
	return ("Grade too high");
}

const char *Form::FormNotSignedException::what() const throw()
{
	return ("Form not signed");
}

Form::~Form()
{
	std::cout << "[Form destructor called]" << std::endl;
}