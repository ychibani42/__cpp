/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychibani <ychibani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 13:31:48 by ychibani          #+#    #+#             */
/*   Updated: 2023/01/17 19:08:09 by ychibani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FORM_HPP__
# define __FORM_HPP__

# include <iostream>
# include "Bureaucrat.hpp"

# define __SIGNED	1
# define __UNSIGNED	-1
# define DEBUG		0

class Bureaucrat;

class Form
{
	public :
		Form();
		Form(const std::string name, bool is_signed, unsigned int rqrd_sgnd_grd, unsigned int rqrd_xct_grd);
		Form (const Form &);
		Form &operator=(const Form &);
		~Form();
		class GradeTooHighException : public std::exception
		{
			public :
				virtual const char *what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public :
				virtual const char *what() const throw();
		};
	const std::string	&getName(void);
	unsigned	int		get_min_rqrd_sgnd_grd() const;
	unsigned	int		get_min_rqrd_xct_grd() const;
	bool				get_is_signed() const;
	void				beSigned(Bureaucrat &bureaucrat);
	private :
		const std::string	__name;
		bool				__is_signed;
		const unsigned int	__rqrd_sgnd_grd;
		const unsigned int	__rqrd_xct_grd;
};

std::ostream &operator<<(std::ostream &, Form &);

#endif