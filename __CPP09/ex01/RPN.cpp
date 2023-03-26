/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychibani <ychibani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 16:47:53 by ychibani          #+#    #+#             */
/*   Updated: 2023/03/26 18:53:19 by ychibani         ###   ########.fr       */
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

void operation(int a, int b, char op, std::stack<int> arr){
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

	for (size_t i = 0; i < str.size(); i++)
	{
		if (is_operator(str[i]))
		{
			int a = __list.top();
			__list.pop();
			int b = __list.top();
			__list.pop();
			operation(a, b, str[i], __list);
			i++;
		}
		else
		{
			__list.push(atoi(str.c_str() + i));
			while (is_digit(str[i]))
				i++;
		}
	}
	return (__list.top());
}

RPN &RPN::operator=(const RPN &cpy)
{
	this->__list = cpy.__list;
	return (*this);
}