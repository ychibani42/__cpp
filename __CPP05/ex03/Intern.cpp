/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychibani <ychibani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 13:30:40 by ychibani          #+#    #+#             */
/*   Updated: 2023/01/16 13:47:45 by ychibani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern(){}
Intern::Intern(Intern const & src){*this = src;}
Intern::~Intern(){}
Intern &Intern::operator=(Intern const & src)
{
	if (this != &src)
		return *this;
	return *this;
}

Form *Intern::makeForm(std::string formName, std::string target)
{
	Form* 		forms[NBR_FORMS] = {new PresidentialPardonForm(target), new RobotomyRequestForm(target), new ShrubberyCreationForm(target)};
	std::string names[NBR_FORMS] = {"presidential pardon", "robotomy request", "shrubbery creation"};
	int i = 0;

	for(; i < NBR_FORMS; ++i)
		if (names[i] == formName)
			break;
	for(int j = 0; j < NBR_FORMS; ++j)
		if (i != j)
			delete forms[j];
	if (i == NBR_FORMS)
	{
		std::cerr << "Intern didn't find form " << formName << std::endl;
		return (NULL);
	}
	else
	{
		std::cout << "Intern has created form " << formName << std::endl;
		return (forms[i]);
	}
}

Form *Intern::makeShrubberyCreationForm(std::string target)
{
	return new ShrubberyCreationForm(target);
}

Form *Intern::makeRobotomyRequestForm(std::string target)
{
	return new RobotomyRequestForm(target);
}

Form *Intern::makePresidentialPardonForm(std::string target)
{
	return new PresidentialPardonForm(target);
}
