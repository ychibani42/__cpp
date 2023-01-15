/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychibani <ychibani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 14:50:17 by ychibani          #+#    #+#             */
/*   Updated: 2023/01/13 14:37:47hibani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "Bureaucrat.hpp"
#include "Form.hpp"

int     main(void)
{
        std::cout << std::endl;
        std::cout << "------------ TEST BUREAUCRAT CLASS ------------" << std::endl;
        std::cout << std::endl;
        std::cout << std::endl;
        std::cout << "------------ Test upper limit ------------" << std::endl;
        std::cout << std::endl;

        Bureaucrat              yassine("ychibani", 3);

        for (int i = 0; i < 3; i++)
        {
                try
                {
                        yassine.promotion();
                        std::cout << yassine << std::endl;
                }
                catch (std::exception const & e)
                {
                        std::cout << e.what() << std::endl;
                }
        }

        std::cout << std::endl;
        std::cout << "------------ Test lower limit ------------" << std::endl;
        std::cout << std::endl;

        Bureaucrat              dylan("dylan", 148);

        for (int i = 0; i < 3; i++)
        {
                try
                {
                        dylan.derank();
                        std::cout << dylan << std::endl;
                }
                catch (std::exception const & e)
                {
                        std::cout << e.what() << std::endl;
                }
        }

        std::cout << std::endl;
        std::cout << "------------ Test invalid contructor value ------------" << std::endl;
        std::cout << std::endl;

        try
        {
                Bureaucrat              uncle("uncle", 1000);
                std::cout << uncle << std::endl;
        }
        catch (std::exception const & e)
        {
                std::cout << e.what() << std::endl;
        }

        try
        {
                Bureaucrat              uncle("uncle", 0);
                std::cout << uncle << std::endl;
        }
        catch (std::exception const & e)
        {
                std::cout << e.what() << std::endl;
        }
        std::cout << std::endl;
        std::cout << "------------ TEST FORM CLASS ------------" << std::endl;
        std::cout << std::endl;

        std::cout << std::endl;
        std::cout << "------------ Test too low to sign ------------" << std::endl;
        std::cout << std::endl;
        try
        {
                Bureaucrat              goodGuy("good guy", 31);
                Form                    plantTree("plant tree", false, 30, 40);

                std::cout << goodGuy << std::endl;
                goodGuy.signForm(plantTree);
                goodGuy.promotion();
                std::cout << goodGuy << std::endl;
                goodGuy.signForm(plantTree);
                std::cout << plantTree << std::endl;
                yassine.signForm(plantTree);
                std::cout << plantTree << std::endl;
        }
        catch (std::exception const & e)
        {
                std::cout << e.what();
        }
        std::cout << std::endl;
        std::cout << "------------ Test invalid constructor value ------------" << std::endl;
        std::cout << std::endl;
        try
        {
                const Form              invalid_form = Form("invalid form", false, 0, 30);
        }
        catch (std::exception const & e)
        {
                std::cout << e.what() << std::endl;
        }
        try
        {
                const Form              invalid_form = Form("invalid form", false , 30, 0);
        }
        catch (std::exception const & e)
        {
                std::cout << e.what() << std::endl;
        }
        try
        {
                const Form              invalid_form = Form("invalid form", false, 151, 40);
        }
        catch (std::exception const & e)
        {
                std::cout << e.what() << std::endl;
        }
        try
        {
                const Form              invalid_form = Form("invalid form", false, 20, 151);
        }
        catch (std::exception const & e)
        {
                std::cout << e.what() << std::endl;
        }
        return (0);
}