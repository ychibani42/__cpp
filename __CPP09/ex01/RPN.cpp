/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychibani <ychibani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 16:47:53 by ychibani          #+#    #+#             */
/*   Updated: 2023/03/27 13:43:14 by ychibani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN()
{
	
}

RPN::~RPN()
{

}

RPN::RPN(RPN &cpy)
{
	*this = cpy;
}


void	print_list(std::stack<int> arr)
{
	while (!arr.empty())
	{
		std::cout << arr.top() << std::endl;
		arr.pop();
	}
}

void operation(int a, int b, char op, std::stack<int> &arr){
   //Perform operation
   if(op == '+')
      arr.push(b+a);
   else if (op == '-')
      arr.push(b-a);
   else if (op == '*')
      arr.push(b*a);
   else if (op == '/')
      arr.push(b/a);
   else if (op == '^')
      arr.push(pow(b, a));
   else
      throw ("can't convert");
}

int	RPN::do_op(std::string str)
{
	std::istringstream ss(str);
	std::string token;

	if (str.empty())
		throw std::range_error("Empty string");
	while (ss >> token)
	{
		if (is_operator(token[0]) && token.size() > 1)
			throw std::range_error("Invalid operator");
		if (is_operator(token[0]))
		{
			if (__list.size() < 2)
				throw std::range_error("Not enough numbers");
			int a = __list.top();
			__list.pop();
			int b = __list.top();
			__list.pop();
			operation(a, b, token[0], __list);
		}
		else
			__list.push(atoi(token.c_str()));
	}
	if (__list.size() > 1)
				throw std::range_error("Too much numbers");
	return (__list.top());
}

RPN &RPN::operator=(const RPN &cpy)
{
	this->__list = cpy.__list;
	return (*this);
}