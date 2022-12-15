/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychibani <ychibani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 11:27:19 by ychibani          #+#    #+#             */
/*   Updated: 2022/12/15 12:25:06 by ychibani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include "includes.hpp"

class Contact
{
	public:
		Contact(void);
		~Contact(void);

		void __set_name( std::string &str );
		void __set_lastname( std::string &str );
		void __set_nickname( std::string &str );
		void __set_phonenumber( std::string &str );
		void __set_darkest_secret( std::string &str );

		std::string __get_name ( void );
		std::string __get_last_name ( void );
		std::string __get_nickname( void );
		std::string	__get_phonenumber( void );
		std::string __get_darkest_secret( void );		
	private:
		std::string	__name;
		std::string	__last_name;
		std::string	__nickname;
		std::string	__phone_number;
		std::string	__darkest_secret;
};

#endif