/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychibani <ychibani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 16:31:49 by ychibani          #+#    #+#             */
/*   Updated: 2023/03/26 18:20:20 by ychibani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <RPN.hpp>

void	error()
{
	std::cout << "Error" << std::endl;
}

int	is_operator(char ch)
{
	if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^')	
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
	for (size_t i = 0; i < str.size(); i++)
	{
		if (!is_operator(str[i]) && str[i] != ' ' && !is_digit(str[i]))
			return (__FAILURE);
	}
	return (1);
}

int main(int ac, char **av)
{
	RPN	list;

	if (!(ac == 2))
		return (error(), __FAILURE);
	if (parse(av[1]) == __FAILURE)
		return (error(), __FAILURE);
	int res = list.do_op(av[1]);
	std::cout << res << std::endl;
	return (__SUCCESS);
}