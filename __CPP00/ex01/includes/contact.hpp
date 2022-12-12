/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychibani <ychibani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 11:27:19 by ychibani          #+#    #+#             */
/*   Updated: 2022/12/12 14:46:47 by ychibani         ###   ########.fr       */
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

		void set_contact(void);
		void set_name(void);
		void set_last_name(void);
		void set_nickname(void);
		void set_phone_number(void);
		void set_darkest_secret(void);
		
	private:
		std::string __get_first_name;
		std::string __get_last_name;
		std::string __get_nickname;
		std::string __phone_number;
		std::string __darkest_secret;


};

#endif