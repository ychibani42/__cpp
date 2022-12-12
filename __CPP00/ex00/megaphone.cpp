/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychibani <ychibani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 10:57:00 by ychibani          #+#    #+#             */
/*   Updated: 2022/12/07 14:27:58 by ychibani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

void
	__to_upper(int ac, char **av)
{
	int	i;
	int	j;

	j = 1;
	while (j < ac)
	{
		i = 0;
		while (av[j][i])
		{
			av[j][i] = std::toupper(av[j][i]);
			i++;
		}
		j++;
	}
}

int
	main(int ac, char **av)
{
	int	i;

	i = 1;
	if (!av)
		return (1);
	if (!(ac > 1))
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else
		__to_upper(ac, av);
	while (i < ac)
		std::cout << av[i++];
	std::cout << "" << std::endl;
	return (1);
}
