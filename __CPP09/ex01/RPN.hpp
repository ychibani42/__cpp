/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychibani <ychibani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 16:33:24 by ychibani          #+#    #+#             */
/*   Updated: 2023/03/26 18:49:26 by ychibani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __RPN_HPP__
# define __RPN_HPP__

#include <iostream>
#include <stdlib.h>
#include <string>
#include <stack>
#include <cmath>

# ifndef __SUCCESS
#  define __SUCCESS 1
# endif

# ifndef __FAILURE
#  define __FAILURE -1
# endif

# ifndef __TRUE
#  define __TRUE 1
# endif

# ifndef __FALSE
#  define __FALSE 0
# endif


class RPN
{
	public:
		RPN();
		RPN(RPN &);
		~RPN();
		RPN &operator=(const RPN &);
		std::stack<int> getList(void) const;
		int	do_op(std::string str);
	private :
		std::stack<int> __list;
};

int	is_operator(char ch);
int	is_digit(char ch);

#endif