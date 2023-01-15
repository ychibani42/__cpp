/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychibani <ychibani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 14:50:37 by ychibani          #+#    #+#             */
/*   Updated: 2023/01/15 18:03:39 by ychibani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __BUREAUCRAT_HPP__
# define __BUREAUCRAT_HPP__

# include <iostream>
# include "Form.hpp"

# define __SUCCESS 1
# define __FAILURE 0

class Form;

class Bureaucrat
{
	public :
		Bureaucrat(void);
		Bureaucrat(const Bureaucrat &);
		Bureaucrat(const std::string name, int grade);
		Bureaucrat &operator=(const Bureaucrat &);
		~Bureaucrat(void);
		
		const std::string	&get_name(void);
		void		set_name(const std::string &name);
		void		set_rank(int rank);
		unsigned int			get_rank(void) const ;
		void		promotion();
		void		derank();
		void		signForm(Form &form);
		void		executeForm(Form const &form);
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

	private :
		const std::string	__name;
		unsigned int			__grade;
};

std::ostream &operator<<(std::ostream &, Bureaucrat &);

#endif