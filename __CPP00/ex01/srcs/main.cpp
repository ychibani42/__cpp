/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychibani <ychibani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 11:39:58 by ychibani          #+#    #+#             */
/*   Updated: 2022/12/19 17:16:44 by ychibani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.hpp"
#include "contact.hpp"
#include "phonebook.hpp"

int	main(void)
{
	std::string	str;
	Phonebook	Phonebook;

	Phonebook.welcome();
	while (true)
	{
		std::cout << "PhoneBook > ";
		std::getline(std::cin, str);
		if (std::cin.eof() || !str.compare(QUIT))
			Phonebook.exit();
		if (str == "ADD")
			Phonebook.add();
		else if (str == "SEARCH")
			Phonebook.search();
		else
			std::cout << "pls put ADD, SEARCH or EXIT" << std::endl;
	}
	return (__SUCCESS);
}
