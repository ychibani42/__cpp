/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychibani <ychibani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 14:57:00 by ychibani          #+#    #+#             */
/*   Updated: 2023/01/15 18:14:14 by ychibani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(){}
Bureaucrat::~Bureaucrat(){}
Bureaucrat::Bureaucrat(const Bureaucrat &cpy){*this = cpy;}
Bureaucrat::Bureaucrat(const std::string name, int grade) : __name(name), __grade(grade)
{
	if (__grade <= 0)
		throw (Bureaucrat::GradeTooHighException());
	else if (__grade > 150)
		throw (Bureaucrat::GradeTooLowException());
	else
		return ;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &to_assign)
{
	if (this == &to_assign)
		return (*this);
	*this = to_assign;
	this->__grade = to_assign.__grade;
	return (*this);
}

void Bureaucrat::promotion()
{
	if (this->__grade - 1 <= 0)
		throw (Bureaucrat::GradeTooHighException());
	std::cout << "Congrulations ! you got promoted !" << std::endl;
	this->__grade -= 1;
}

void	Bureaucrat::signForm(Form &form)
{
	try 
	{
		form.beSigned(*this);
		std::cout << this->__name << " signed " << form.getName() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << this->__name << " cannot sign " << form.getName() << " because" << e.what() << std::endl;
	}	
}

void	Bureaucrat::executeForm(Form const &form)
{
	try
	{
		form.execute(*this);
		std::cout << this->__name << " executed " << form.getName() << std::endl;
	}
	catch
	{
		std::cerr << this->__name << " cannot execute " << form.getName() << " because" << e.what() << std::endl;
	}
}

void Bureaucrat::derank()
{
	if (this->__grade + 1 > 150)
		throw (Bureaucrat::GradeTooLowException());
	std::cout << "Ouch ! you got deranked !" << std::endl;
	this->__grade += 1;
}

void					Bureaucrat::set_rank(int rank) {this->__grade = rank;};
const 		std::string	&Bureaucrat::get_name(void) {return (this->__name);}
unsigned int			Bureaucrat::get_rank(void) const {return (this->__grade);}

std::ostream &operator<<(std::ostream &os, Bureaucrat &bureau)
{
	os << bureau.get_name() << ", bureaucrat grade " << bureau.get_rank() << ".";
	return (os);
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade too Low");
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade too High");
}