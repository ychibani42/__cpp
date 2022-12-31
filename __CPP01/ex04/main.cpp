/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychibani <ychibani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 17:44:47 by ychibani          #+#    #+#             */
/*   Updated: 2022/12/30 15:52:43 by ychibani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.hpp"

void	usage(void)
{
	std::cerr << "Usage : <infile> <string you want to replace> <string you want to replace with>" << std::endl;
}

void	open_error(std::string infile)
{
	std::cerr << "Cannot open : " << "[" << infile << "]" << std::endl;
}

void	dir_error(std::string infile)
{
	std::cerr << infile << ": Is a directory" << std::endl;
}

int
	main(int ac, char **av)
{
	std::string	line;
	std::string	infile;
	std::string	replace_wd;
	std::string	str_to_replace;
	std::string	outfile;
	struct stat file_stat;

	if (!(ac == 4) || !std::strlen(av[1]) || !std::strlen(av[2]))
		return (usage(), __FAILURE);
	infile = av[1];
	replace_wd = av[2];
	str_to_replace = av[3];
	if (!stat(infile.c_str(), &file_stat))
	{
		if (S_ISDIR(file_stat.st_mode))
		return (dir_error(infile), __FAILURE);
	}
	std::ifstream	input_file(infile.c_str());
	if (!input_file.is_open())
		return (open_error(infile), 2);
	outfile = infile.append(".replace");
	std::ofstream	output_file(outfile.c_str());
	if (!output_file.is_open())
		return (open_error(outfile), 2);
	while (std::getline(input_file, line))
	{
		while (true)
		{
			size_t ret = line.find(replace_wd);
			if (ret == std::string::npos)
			{
				output_file << line;
				break;
			}
			else
			{
				output_file << line.substr(0, ret);
				output_file << str_to_replace;
				line = line.substr(ret + replace_wd.size());
			}
		}
		output_file << std::endl;
	}

	return (input_file.close(), output_file.close(), __SUCCESS);
}
