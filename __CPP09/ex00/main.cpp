#include "BitcoinExchange.hpp"

void usage(void)
{
	std::cerr << "Error: could not open file." << std::endl;
}

void dir_error(std::string infile)
{
	std::cerr << infile << ": is a directory" << std::endl;
}

void open_error(std::string infile)
{
	std::cerr << infile << ": cannot be open" << std::endl;
}

void is_reg(std::string infile)
{
	std::cerr << infile << ": is not a regular file" << std::endl;
}

int     daysInMonth(int month)
{
    if (month > 7)
        return (31 - (month % 2));
    if (month % 2 == 0)
        return (30);
    return (31);
}

int is_valid_date(int year, int month, int day)
{   
    if (month < 1 || month > 12 || day < 1)
        return __FAILURE;
    else if (month == 2)
    {
        if (day < 29 || (day == 29 && (year % 4 == 0 || (year % 100 == 0 && year % 400 != 0))))
            return __SUCCESS;
        return __FAILURE;
    }
    else if (day > daysInMonth(month))
        return __FAILURE;
    return (__SUCCESS);
}

int check_date(std::string date)
{
	std::basic_string<char>::size_type i = 0;
	int year, month, day;

	if (date.size() != 10)
		return (__FAILURE);
	if (date[4] != '-' || date[7] != '-')
		return (__FAILURE);
	for (i = 0; i < date.size(); i++)
		if (date[i] == '-')
			date[i] = ' ';
	std::istringstream nb(date);
	nb >> year;
	nb >> month;
	nb >> day;
	if (is_valid_date(year, month, day) == __FAILURE)
		return (__FAILURE);
	return (__SUCCESS);
}

int check_value(std::string value)
{
	std::istringstream nb(value);
	std::basic_string<char>::size_type i = 0;
	double to_check;

	nb >> to_check;
	if (to_check < 0)
		return (4);
	for (i = 0; i < value.size(); i++)
	{
		if (value[i] == '.' && i != 0)
			break;
		if (!isdigit(value[i]))
			return (2);
	}
	for (i++; i < value.size(); i++)
	{
		if (!isdigit(value[i]))
			return (2);
	}
	if (to_check > 1000)
		return (3);
	else if (to_check < 0)
		return (4);
	else
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

int trim_and_split(std::string line, BitcoinExchange tree)
{
	std::string value;
	std::string date;
	std::istringstream tmp_year(line);
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
	std::istringstream mult_value(value);
	double value_mult;
	mult_value >> value_mult;
	try
	{
		std::cout << date << " => " << value << " = " << std::setprecision(2) << tree.getBtcValue(date) * value_mult  << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return (__SUCCESS);
}

int parse(char **av, BitcoinExchange tree)
{
	struct stat file_stat;

	std::string infile = av[1];
	std::ifstream input_file(infile.c_str());
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
	if (!(ac == 2) || !std::strlen(av[1]))
		return (usage(), 2);
	file = "data.csv";
	try
	{
		BitcoinExchange tree(file);
		parse(av, tree);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}
