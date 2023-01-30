/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychibani <ychibani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 14:02:08 by ychibani          #+#    #+#             */
/*   Updated: 2023/01/15 17:52:35 by ychibani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : Form("ShrubberyCreationForm", false, 145, 137){}
ShrubberyCreationForm::~ShrubberyCreationForm(){}
ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : Form("ShrubberyCreationForm", false, 145, 137), _target(target){}
ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &src) : Form(src), _target(src._target){}
ShrubberyCreationForm	&ShrubberyCreationForm::operator=(ShrubberyCreationForm const &rhs)
{
	_target = rhs._target;
	return (*this);
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	std::ifstream ifs;
	std::string filename = _target + "_shrubbery";
	
	if (this->get_is_signed() == false)
		throw Form::FormNotSignedException();
	if (executor.get_rank() > this->get_min_rqrd_xct_grd())
		throw Form::GradeTooLowException();
	ifs.open(filename.c_str());
	if (ifs.is_open())
	{
		std::cout << "File already exists or can't be open" << std::endl;
		ifs.close();
		return ;
	}
	else
	{
		std::ofstream ofs;
		std::cout << "File created !" << std::endl;
		ofs.open(filename.c_str());
		ofs << "          ,@@@@@@@,          " << std::endl;
		ofs << "      ,,,.   ,@@@@@@/@@,  .oo8888o.          " << std::endl;
		ofs << "   ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o          " << std::endl;
		ofs << "  ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'          " << std::endl;
		ofs << "  %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'          " << std::endl;
		ofs << "  %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'          " << std::endl;
		ofs << "  `&%\\ ` /%&'    |.|        \\ '|8'          " << std::endl;
		ofs << "      |o|        | |         | |          " << std::endl;
		ofs << "      |.|        | |         | |          " << std::endl;
		ofs << "  \\/ ._\\//_/__/  ,\\_//__\\/.  \\_//__/_          " << std::endl;
		ofs.close();
	}
}
