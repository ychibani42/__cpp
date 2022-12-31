/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychibani <ychibani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 13:47:33 by ychibani          #+#    #+#             */
/*   Updated: 2022/12/30 20:53:12 by ychibani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

#include "ClapTrap.hpp"

int main(void)
{
    std::cout << "### TESTING CLAPTRAP ###\n" << std::endl;

    std::cout << "\033[34mConstructing\033[0m" << std::endl;
    ClapTrap a("Barnar");
    ClapTrap b("Arnaud");
    std::cout << "\033[34mTesting\033[0m" << std::endl;
    a.attack("some other robot");
    a.takeDamage(10);
    a.takeDamage(10);
    a.beRepaired(5);
    a.attack("some other other robot");
    b.beRepaired(3);
    for (int i = 0; i < 12; i++)
        b.attack("Cody-clone");
    b.beRepaired(3);
    std::cout << "\033[34mDeconstructing\033[0m" << std::endl;
}