#include "BitcoinExchange.hpp"

void	usage(void)
{
	std::cerr << "usage : ./btc <file_name>" << std::endl;
}

void	dir_error(std::string infile)
{
	std::cerr << infile << ": is a directory" << std::endl;
}

void	open_error(std::string infile)
{
	std::cerr << infile << ": cannot be open" << std::endl;
}

void	is_reg(std::string infile)
{
	std::cerr << infile << ": is not a regular file" << std::endl;
}

int	check_date(std::string date)
{
	std::basic_string<char>::size_type i = 0;
	int to_check;

	if (date.size() != 10)
		return (__FAILURE);
	if (date[4] != '-' || date[7] != '-')
		return (__FAILURE);
	for (i = 0; i < date.size(); i++)
		if (date[i] == '-')
			date[i] = ' ';
	std::istringstream nb(date);
	i = 0;
	while (nb >> to_check)
	{
		if (i == 0)
		{
			if (to_check < 2009 || to_check > 2023)
				return (__FAILURE);
		}
		else if (i == 1)
		{
			if (to_check < 1 || to_check > 12)
				return (__FAILURE);
		}
		else
		{
			if (to_check < 1 || to_check > 31)
				return (__FAILURE);
		}
		i++;
	}
	return (__SUCCESS);
}

int	check_value(std::string value)
{
	std::istringstream nb(value);
	std::basic_string<char>::size_type i = 0;
	double to_check;

	nb >> to_check;
	if (to_check < 0)
		return (4);
	if (value.size() > 11)
		return (3);
	for (i = 0; i < value.size(); i++)
	{
		if (value[i] == '.' && i != 0)
			break;
		if (!isdigit(value[i]))
			return (2);
	}
	for (i++ ; i < value.size(); i++)
	{
		if (!isdigit(value[i]))
			return (2);
	}
	if (to_check > INT_MAX)	
		return (3);
	return (__SUCCESS);
}

void too_big_nb()
{
	std::cout << "Error: too large number." << std::endl;
}

void too_low_nb()
{
	std::cout << "Error: not a positive number." << std::endl;
}

void not_a_number()
{
	std::cout << "Error: invalid input." << std::endl;
}

void bad_input(std::string line)
{
	std::cout << "Error: bad input => " << line << std::endl;
}

int	trim_and_split(std::string line, BitcoinExchange tree)
{
	std::string value;
	std::string date;
	std::istringstream	tmp_year(line);
	if (tmp_year.fail() || tmp_year.eof())
		return (__FAILURE);
	std::getline(tmp_year, date, '|');
	tmp_year >> value;
	date.erase(date.end() - 1);
	if (check_date(date) == __FAILURE)
		return (bad_input(line), __FAILURE);
	int res = check_value(value);
	if (res == 4)
		return (too_low_nb(), __FAILURE);
	else if (res == 2)
		return (not_a_number(), __FAILURE);
	else if (res == 3)
		return (too_big_nb(), __FAILURE);
	std::istringstream	mult_value(value);
	double value_mult;
	mult_value >> value_mult;
	try
	{
		std::cout << date << " => " << value << " = " << tree.getBtcValue(date) * value_mult << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Can't convert because : " << e.what() << std::endl;
	}
	return (__SUCCESS);
}

int parse(char **av, BitcoinExchange tree)
{
	struct stat file_stat;

	std::string infile = av[1];
    std::ifstream   input_file(infile.c_str());
    if (!stat(infile.c_str(), &file_stat))
    {
	    if (S_ISDIR(file_stat.st_mode))
			return (dir_error(infile), __FAILURE);
		if (!S_ISREG(file_stat.st_mode))
				return (is_reg(infile), __FAILURE);
        if (!input_file.is_open())
                return (open_error(infile), __FAILURE);
	}
	if (is_empty(input_file))
		throw std::range_error("Empty input File");
	std::string line;
	while (std::getline(input_file, line))
	{
		if (line[0] == '#' || line.empty() || line == "date | value")
			continue;
		trim_and_split(line, tree);
	}
	input_file.close();
	return (__SUCCESS);
}


int main(int ac, char **av)
{
	std::string file;
	if (!(ac == 2 || ac == 3) || !std::strlen(av[1]))
		return (usage(), 2);
	if (ac == 3)
		file = av[2];
	else
		file = "data.csv";
	try
	{
		BitcoinExchange tree(file);
		parse(av, tree);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}
