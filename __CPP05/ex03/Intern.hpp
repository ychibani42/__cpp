/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychibani <ychibani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 13:29:12 by ychibani          #+#    #+#             */
/*   Updated: 2023/01/16 13:47:11 by ychibani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __INTERN_HPP__
# define __INTERN_HPP__

# include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

# define NBR_FORMS 3

class Intern
{
	public:
		Intern();
		Intern(Intern const & src);
		~Intern();

		Intern &		operator=(Intern const & src);

		Form *makeForm(std::string formName, std::string target);
		Form *makeShrubberyCreationForm(std::string target);
		Form *makeRobotomyRequestForm(std::string target);
		Form *makePresidentialPardonForm(std::string target);	
};

#endif