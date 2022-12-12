/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychibani <ychibani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 11:39:58 by ychibani          #+#    #+#             */
/*   Updated: 2022/12/12 15:22:22 by ychibani         ###   ########.fr       */
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
	Phonebook.addUser();
	while (true)
	{
		std::cout << "PhoneBook > ";
		std::getline(std::cin, str);
		if (std::cin.eof() || !str.compare(QUIT))
			break;
		if (str == "ADD")
			Phonebook.add();
		// else if (str == "SEARCH")
			// Phonebook.search();
		// else
			// std::cout << "I don't like to repeat but, pls put ADD, SEARCH or EXIT" << std::endl;
	}
	return (__SUCCESS);
}
