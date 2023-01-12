/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychibani <ychibani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 14:50:37 by ychibani          #+#    #+#             */
/*   Updated: 2023/01/12 14:28:45 by ychibani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __BUREAUCRAT_HPP__
# define __BUREAUCRAT_HPP__

# include <iostream>

# define __SUCCESS 1
# define __FAILURE 0

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
		int			get_rank(void);
		void		promotion();
		void		derank();
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
		int			__grade;
};

std::ostream &operator<<(std::ostream &, Bureaucrat &);

#endif