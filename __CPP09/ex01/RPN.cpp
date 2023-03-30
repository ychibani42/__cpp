/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychibani <ychibani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 16:47:53 by ychibani          #+#    #+#             */
/*   Updated: 2023/03/30 10:04:20 by ychibani         ###   ########.fr       */
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

void print_list(std::stack<int> arr)
{
	while (!arr.empty())
	{
		std::cout << arr.top() << std::endl;
		arr.pop();
	}
}

void operation(int a, int b, char op, std::stack<int> &arr)
{
	int res = 0;

	if (op == '+')
	{
		if (b + a > INT_MAX || b + a < INT_MIN)
			throw std::range_error("res too big or too low");
		res = b + a;
	}
	else if (op == '-')
	{
		if (b - a > INT_MAX || b - a < INT_MIN)
			throw std::range_error("res too big or too low");
		res = (b - a);
	}
	else if (op == '*')
	{
		if (b * a > INT_MAX || b * a < INT_MIN)
			throw std::range_error("res too big or too low");
		res = (b * a);
	}
	else if (op == '/')
	{
		if (!a || !b)
			throw std::range_error("Can't divide number by 0");
		if (b / a > INT_MAX || b / a < INT_MIN)
			throw std::range_error("res too big or too low");
		res = b / a;
	}
	else if (op == '^')
	{
		if (pow(b, a) > INT_MAX || pow(b, a) < INT_MIN)
			throw std::range_error("res too big or too low");
		res = pow(b, a);
	}
	else
		throw ("Can't convert");
	arr.push(res);
}

int	is_number(std::string str)
{
	size_t	start = 0;
	if (str[0] == '-' && is_digit(str[1]))
		start = 1;
	for (size_t i = start; i < str.size(); i++)
	{
		if (!is_digit(str[i]))
			return (__FALSE);
	}
	if (str.size() - start > 1)
		return (__FALSE);
	return (__TRUE);
}

int RPN::do_op(std::string str)
{
	std::istringstream ss(str);
	std::string token;

	if (str.empty())
		throw std::range_error("Empty string");
	while (ss >> token)
	{
		if (is_number(token))
			__list.push(atoi(token.c_str()));
		else if (is_operator(token))
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
			throw std::range_error("Error");
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