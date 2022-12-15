/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychibani <ychibani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 17:22:56 by ychibani          #+#    #+#             */
/*   Updated: 2022/12/15 15:28:25by ychibani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.hpp"
#include "phonebook.hpp"
#include "contact.hpp"
#include <sstream>
#include <string>

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

void	Phonebook::set_contact(int index)
{
	std::string buffer;

	std::cout << "Enter Your Name : ";
	std::getline(std::cin, buffer);
	if (std::cin.eof()) this->exit();
	__phone_book[index].__set_name(buffer);

	std::cout << "Enter Your Lastname : ";
	std::getline(std::cin, buffer);
	if (std::cin.eof()) this->exit();
	__phone_book[index].__set_lastname(buffer);

	std::cout << "Enter Your Phonenumber : ";
	std::getline(std::cin, buffer);
	if (std::cin.eof()) this->exit();
	__phone_book[index].__set_phonenumber(buffer);

	std::cout << "Enter Your Nickname : ";
	std::getline(std::cin, buffer);
	if (std::cin.eof()) this->exit();
	__phone_book[index].__set_nickname(buffer);

	std::cout << "Enter Your Darkest Secret 😈: ";
	std::getline(std::cin, buffer);
	if (std::cin.eof()) this->exit();
	__phone_book[index].__set_darkest_secret(buffer);
	std::cout << "Well done, you entered all your contacts like a boss!" << std::endl;
}

void	Phonebook::add( void )
{
	if (this->__contact_added >= MAX_CONTACT_ALLOWED)
		this->__index = __contact_added % MAX_CONTACT_ALLOWED;
	Phonebook::set_contact(this->__index);
	this->__contact_added += 1;
	this->__index += 1;
}

void	Phonebook::__print_elem(std::string str)
{
	if (str.size() > PADDING)
		std::cout << str.substr(0, PADDING - 1) << ".";
	else
		std::cout << std::setw(PADDING) << str;
}

void	Phonebook::__print_line(std::string index, std::string s1, std::string s2, std::string s3)
{
	std::cout << "|";
	__print_elem(index);
	std::cout << "|";
	__print_elem(s1);
	std::cout << "|";
	__print_elem(s2);
	std::cout << "|";
	__print_elem(s3);
	std::cout << "|" << std::endl;
}

void	Phonebook::search( void )
{
	std::string buffer;
	std::ostringstream	integer;
	
	const int	max = ((this->__contact_added > MAX_CONTACT_ALLOWED) ? MAX_CONTACT_ALLOWED : this->__contact_added);

	__print_line("index", "first_name", "last_name", "nickname");
	for(int i = 0; i < max; i++)
	{
		integer << i;
		__print_line(integer.str(), this->__phone_book[i].__get_name(), this->__phone_book[i].__get_last_name(), this->__phone_book[i].__get_nickname());
	}
	integer.clear();
	while (true)
	{
		std::cout << "Index >";
		std::getline(std::cin, buffer);
		if (std::cin.eof() || !buffer.compare(QUIT))
			break ;
		else
		{
			std::cout << std::stringstream(buffer) << std::endl	;
		}
			
	}
}

void	Phonebook::exit( void )
{
	std::cout << std::endl <<"Bye Have a good time" << std::endl;
	std::exit(EXIT_SUCCESS);
}