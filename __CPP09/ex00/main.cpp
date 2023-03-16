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
			if (to_check < 2000 || to_check > 2023)
				return (__FAILURE);
		}
		else if (i == 1)
		{
			if (to_check < 1 || to_check > 11)
				return (__FAILURE);
		}
		else
		{
			if (to_check < 1 || to_check > 30)
				return (__FAILURE);
		}
		i++;
	}
	return (__SUCCESS);
}

int	check_value(std::string value)
{
	for (i = 0; i < date.size(); i++)
		if (date[i] == '-')
			date[i] = ' ';
	std::istringstream	nb(value);

	return (__SUCCESS);
}

int	trim_and_split(std::string line)
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
		return (__FAILURE);
	return (__SUCCESS);
	if (check_value(value) == __FAILURE)
		return (__FAILURE);
}

int parse(char **av)
{
	BitcoinExchange	tree_to_set;
	struct stat file_stat;

	std::string infile = av[1];
	std::string csv = "data.csv";
    std::ifstream   input_file(infile.c_str());
    std::ifstream   csv_file(csv.c_str());
    if (!stat(infile.c_str(), &file_stat))
    {
	    if (S_ISDIR(file_stat.st_mode))
			return (dir_error(infile), __FAILURE);
		if (!S_ISREG(file_stat.st_mode))
				return (is_reg(infile), __FAILURE);
        if (!input_file.is_open())
                return (open_error(infile), __FAILURE);
        if (!csv_file.is_open())
                return (open_error(infile), __FAILURE);
	}
	std::string line;
	while (std::getline(input_file, line))
	{
		if (line[0] == '#' || line.empty() || line == "date | value")
			continue;
		if (trim_and_split(line) == __FAILURE)
			std::cout << "bad input => " << line << std::endl;
	}
	input_file.close();
	csv_file.close();
	return (1);
}

#include <vector>

std::vector<std::string> split(std::string str, std::string delimiter)
{
	std::vector<std::string> values;

	size_t position;
	while ((position = str.find(delimiter)) != std::string::npos)
	{
		values.push_back(str.substr(0, position));
		str.erase(0, position + delimiter.length());
	}
	values.push_back(str);
	return values;
}

int main(int ac, char **av)
{
	if (!(ac == 2) || !std::strlen(av[1]))
		return (usage(), 2);
	if (parse(av) == __FAILURE)
		return (__FAILURE);
}

// utiliser map, prendre la data du .csv, prendre la doneee de la data la plus proche, 
//  map = arbre binaire; donc possibilite de parcourir plus vite 
// faire gaffe aux jours a 30 ou 31 jours
// constructor en forme de string;
// si la date n'existe pas, chercher a la date la plus proche


//exercice 2 stack