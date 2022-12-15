/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychibani <ychibani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 17:21:23 by ychibani          #+#    #+#             */
/*   Updated: 2022/12/15 14:42:36 by ychibani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_CLASS_HPP
# define PHONEBOOK_CLASS_HPP

#include "contact.hpp"


class Phonebook
{
	public:
			Phonebook(void);
			~Phonebook();
	void		search ( void );
	void		add ( void );
	void		welcome ( void );
	void		exit( void );
	private:
			void		set_contact(int index);
			int		__index;
			Contact	__phone_book[MAX_CONTACT_ALLOWED];
			int		__contact_added;
			
			void	__print_line(std::string, std::string, std::string, std::string);
			void	__print_elem(std::string);
};

# endif
