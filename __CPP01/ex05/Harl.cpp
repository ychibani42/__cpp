/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychibani <ychibani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 21:22:22 by ychibani          #+#    #+#             */
/*   Updated: 2022/12/23 22:25:42 by ychibani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl(void)
{
	return ;
}

Harl::~Harl(void)
{
	return ;
}

void	Harl::complain(std::string level)
{
	t_lvl		lvl[4] = {{&Harl::__debug}, {&Harl::__info}, {&Harl::__warning}, {&Harl::__error}};
	std::string	lvl_tab[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	if (level.empty())
		std::cerr << "Empty strings";
	for(int	index = 0; index < 4; index++)
	{
		if (!level.compare(lvl_tab[index]))
			return ((this->*(lvl[index].f))());
	}
	std::cerr << level << " : doesn't Exist !" << std::endl;
}

void	Harl::__debug(void)
{
	std::cout << "						[DEBUG]" << std::endl;
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special- ketchup burger. I really do !" << std::endl;
}

void	Harl::__info(void)
{
	std::cout << "						[INFO]" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger ! If you did, I wouldn’t be asking for more !" << std::endl;
}

void	Harl::__warning(void)
{
	std::cout << "						[WARNING]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void	Harl::__error(void)
{

	std::cout << "						[ERROR]" << std::endl;
	std::cout << "This is unacceptable ! I want to speak to the manager now." << std::endl;
}