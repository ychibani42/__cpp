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

int     main(void)
{
       
		std::cout << "					[SHRUBBERRY FORM TESTS]			" << std::endl;
		std::cout << "					[NOT SIGNED TESTS]			" << std::endl;
		try
		{
			Bureaucrat NotSigned = Bureaucrat("Plouf", 15);
			ShrubberyCreationForm shrub("plants");
			shrub.execute(NotSigned);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		std::cout << "					[NO RIGHTS FORM TESTS]			" << std::endl;
		try
		{
			Bureaucrat Norights = Bureaucrat("Norights", 137);
			ShrubberyCreationForm shrub("plants");
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
		catch(const std::exception& e)
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
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}




		std::cout << "					[PRESIDENTIAL PARDON FORM TESTS]		" << std::endl;
        return (0);
}