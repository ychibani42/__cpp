/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychibani <ychibani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 17:22:56 by ychibani          #+#    #+#             */
/*   Updated: 2022/12/12 15:21:27 by ychibani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.hpp"
#include "phonebook.hpp"

Phonebook::Phonebook( void ) : __index(0), __contact_added(0){
	return ;
}

Phonebook::~Phonebook( void ){
	return ;
}

void	Phonebook::welcome( void )
{
	std::cout << "Welcome to ... your PhoneBook !!" << std::endl;
	std::cout << "Here you can choose to add contacts, search for one, or quit if you like !" << std::endl;
	std::cout << "Here's some command your allowed to do : <ADD> <SEARCH> or <EXIT>" << std::endl;
}

void	Phonebook::add( void )
{
	this->__contact_added += 1;
	if (this->__contact_added >= MAX_CONTACT_ALLOWED)
		this->__phone_book[this->__contact_added % MAX_CONTACT_ALLOWED - 1].set_contact(this->__contact_added % MAX_CONTACT_ALLOWED);
	else
		this->__phone_book[this->__contact_added - 1].set_contact(this->__contact_added);
}

// int	is_digit(std::string str)
// {
// 	for(int	i = 0; i < str.length(); i++)
// 		if (str[i] < '0' || str[i] > '9')
// 			return (0);
// 	return (1);
// }

// int	Phonebook::searchUser(void)
// {
// 	std::string	str = "";
	
// 	while (str == "")
// 	{
// 		if (!is_digit(str))
// 		{
// 			return (-1);
// 		}
// 	}
// }