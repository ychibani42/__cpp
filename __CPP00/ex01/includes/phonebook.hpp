/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychibani <ychibani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 17:21:23 by ychibani          #+#    #+#             */
/*   Updated: 2022/12/12 15:21:34 by ychibani         ###   ########.fr       */
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
	int			search ( void );
	void		add ( void );
	void		welcome ( void );

	private:
			Contact	__phone_book[MAX_CONTACT_ALLOWED];
			int		__index;
			int		__contact_added;
			
			void	__print_line(std::string, std::string, std::string, std::string);
			void	__print_elem(std::string);
};

# endif
