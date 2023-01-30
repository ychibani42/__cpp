/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychibani <ychibani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 14:50:17 by ychibani          #+#    #+#             */
/*   Updated: 2023/01/17 22:09:39 by ychibani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main(void)
{
	std::cout << std::endl;
	std::cout << "------------ Test upper limit ------------" << std::endl;
	std::cout << std::endl;

	Bureaucrat		Yassine("Yassou", 3);

	for (int i = 0; i < 3; i++)
	{
		try
		{
			Yassine.promotion();
			std::cout << Yassine << std::endl;
		}
		catch (std::exception const & e)
		{
			std::cout << e.what() << std::endl;
		}
	}

	std::cout << std::endl;
	std::cout << "------------ Test lower limit ------------" << std::endl;
	std::cout << std::endl;

	Bureaucrat		djenna("Djenna", 148);

	for (int i = 0; i < 3; i++)
	{
		try
		{
			djenna.derank();
			std::cout << djenna << std::endl;
		}
		catch (std::exception const & e)
		{
			std::cout << e.what() << std::endl;
		}
	}

	std::cout << std::endl;
	std::cout << "------------ Test invalid contructor value ------------" << std::endl;
	std::cout << std::endl;
	try
	{
		Bureaucrat		uncle("uncle", 1000);
		std::cout << uncle << std::endl;
	}
	catch (std::exception const & e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		Bureaucrat		uncle("uncle", 0);
		std::cout << uncle << std::endl;
	}
	catch (std::exception const & e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}