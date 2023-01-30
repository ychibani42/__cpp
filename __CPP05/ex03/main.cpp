/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychibani <ychibani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 14:50:17 by ychibani          #+#    #+#             */
/*   Updated: 2023/01/13 14:37:47hibani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"

int     main(void)
{
       
		std::cout << "					[SHRUBBERRY FORM TESTS]			" << std::endl;
		std::cout << "					[NOT SIGNED TESTS]			" << std::endl;
		try
		{
			Bureaucrat NotSigned = Bureaucrat("Plouf", 15);
			ShrubberyCreationForm shrub("Plants");
			shrub.execute(NotSigned);
		}
		catch (const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		std::cout << "					[NO RIGHTS FORM TESTS]			" << std::endl;
		try
		{
			Bureaucrat Norights = Bureaucrat("Norights", 137);
			ShrubberyCreationForm shrub("Plants");
			shrub.beSigned(Norights);
			shrub.execute(Norights);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		std::cout << "					[WORKING TESTS]			" << std::endl;
		try
		{
			Bureaucrat WK = Bureaucrat("Ok", 1);
			ShrubberyCreationForm shrub("Plants");
			shrub.beSigned(WK);
			shrub.execute(WK);
		}
		catch (const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		std::cout << "					[IS EXISTING TESTS]			" << std::endl;
		try
		{
			Bureaucrat AE = Bureaucrat("Already Exist", 1);
			ShrubberyCreationForm shrub("Plants");
			shrub.beSigned(AE);
			shrub.execute(AE);
		}
		catch (const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		std::cout << "					[PRESIDENTIAL PARDON FORM TESTS]		" << std::endl;
		std::cout << "					[NOT SIGNED TESTS]			" << std::endl;
		try
		{
			Bureaucrat NotSigned = Bureaucrat("Plouf", 1);
			PresidentialPardonForm pardon("Plouf");
			NotSigned.executeForm(pardon);
		}
		catch (const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		std::cout << "					[NO RIGHTS FORM TESTS]			" << std::endl;
		try
		{
			Bureaucrat Norights = Bureaucrat("Norights", 26);
			PresidentialPardonForm pardon("Plouf");
			Norights.signForm(pardon);
			Norights.executeForm(pardon);
			while (Norights.get_rank() > 24)
				Norights.promotion();
			Norights.signForm(pardon);
			Norights.signForm(pardon);
		}
		catch (const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		std::cout << "					[WORKING TESTS]			" << std::endl;
		try
		{
			Bureaucrat WK = Bureaucrat("Ok", 1);
			PresidentialPardonForm pardon("Plouf");
			WK.signForm(pardon);
			WK.executeForm(pardon);
		}
		catch (const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		std::cout << "					[ROBOTOMY REQUESTS TESTS]			" << std::endl;
		std::cout << "					[NOT SIGNED TESTS]			" << std::endl;
		try
		{
			Bureaucrat NotSigned = Bureaucrat("Plouf", 1);
			RobotomyRequestForm robot("Plouf");
			robot.execute(NotSigned);
		}
		catch (const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		std::cout << "					[NO RIGHTS FORM TESTS]			" << std::endl;
		try
		{
			Bureaucrat Norights = Bureaucrat("Norights", 43);
			RobotomyRequestForm robot("Plouf");
			Norights.signForm(robot);
			Norights.executeForm(robot);
			while (Norights.get_rank() > 45)
				Norights.promotion();
			Norights.executeForm(robot);
		}
		catch (const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		std::cout << "					[WORKING TESTS]			" << std::endl;
		try
		{
			Bureaucrat WK = Bureaucrat("Ok", 1);
			RobotomyRequestForm robot("Plouf1");
			robot.beSigned(WK);
			robot.execute(WK);
		}
		catch (const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		std::cout << "					[INTERN TESTS]			" << std::endl;
		Intern	someRandomIntern;
		Bureaucrat bob("bob", 1);
		Form	*rrf;
		rrf = someRandomIntern.makeForm("presidential pardon", "Bender");
		if (rrf)
		{
			rrf->beSigned(bob);
			rrf->execute(bob);
		}
		delete rrf;

		rrf = someRandomIntern.makeForm("robotomy request", "Bender");
		if (rrf)
		{
			rrf->beSigned(bob);
			rrf->execute(bob);
		}
		delete rrf;

		rrf = someRandomIntern.makeForm("shrubbery creation", "Bender");
		if (rrf)
		{
			rrf->beSigned(bob);
			rrf->execute(Bureaucrat("lucas", 1));
		}
		delete rrf;

		rrf = someRandomIntern.makeForm("not existing", "Bender");
		return 0;
}