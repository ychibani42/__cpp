/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychibani <ychibani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 16:31:49 by ychibani          #+#    #+#             */
/*   Updated: 2023/04/09 15:10:05 by ychibani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <RPN.hpp>

void	error()
{
	std::cout << "Error" << std::endl;
}

int	is_operator(std::string str)
{
	if (str.size() != 1)
		return (__FALSE);
	if (str[0] == '+' || str[0] == '-' || str[0] == '*' || str[0] == '/' || str[0] == '^')
		return (__TRUE);
	return (__FALSE);
}

int	is_digit(char ch)
{
	if (ch >= '0' && ch <= '9')
		return (__TRUE);
	return (__FALSE);
}

int	parse(std::string str)
{
	std::string s2;
	for (size_t i = 0; i < str.size(); i++)
	{
		s2 = str[i];
		if (!is_operator(s2) && str[i] != ' ' && !is_digit(str[i]) && str[i] != '-')
			return (__FAILURE);
	}
	return (1);
}

int main(int ac, char **av)
{
	RPN	list;

	if ((!(ac == 2)))
		return (error(), __FAILURE);
	if (parse(av[1]) == __FAILURE)
		return (error(), __FAILURE);
	try
	{
		long res = list.do_op(av[1]);
		std::cout << res << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return (__SUCCESS);
}