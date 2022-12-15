/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychibani <ychibani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 11:35:46 by ychibani          #+#    #+#             */
/*   Updated: 2022/12/15 15:04:24 by ychibani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contact.hpp"


Contact::Contact(void){
	
	return ;
}

Contact::~Contact(void)	{
	return ;
}

void	Contact::__set_name(std::string &str) {
	this->__name = str;
}

std::string	Contact::__get_name(void)
{
	return (this->__name);
}

void	Contact::__set_lastname(std::string &str) {
	this->__last_name = str;
}

std::string	Contact::__get_last_name(void)
{
	return (this->__last_name);
}

void	Contact::__set_nickname(std::string &str) {
	this->__nickname = str;
}

std::string	Contact::__get_nickname(void)
{
	return (this->__nickname);
}

void	Contact::__set_phonenumber(std::string &str) {
	this->__phone_number = str;
}

std::string	Contact::__get_phonenumber(void)
{
	return (this->__phone_number);
}

void	Contact::__set_darkest_secret(std::string &str) {
	this->__darkest_secret = str;
}

std::string	Contact::__get_darkest_secret(void)
{
	return (this->__darkest_secret);
}