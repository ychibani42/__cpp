#include "BitcoinExchange.hpp"

bool is_empty(std::ifstream& pFile)
{
    return pFile.peek() == std::ifstream::traits_type::eof();
}

void	BitcoinExchange::__parse_csv(std::string csv_file) 
{
	int size;

	size = csv_file.size() - 4;
	if (size < 1)
		throw std::range_error("Not a .csv file.");
	if (strncmp(".csv", csv_file.c_str() + size, size))
		throw std::range_error("Not a .csv file.");
	struct stat file_stat;
    if (!stat(csv_file.c_str(), &file_stat))
    {
	    if (S_ISDIR(file_stat.st_mode))
			throw std::range_error("Csv file is a dir.");
		if (!S_ISREG(file_stat.st_mode))
			throw std::range_error("Csv file is not a regular file.");
        if (!__csv_file.is_open())
			throw std::range_error("Csv file cannot be openned.");
	}
	std::ifstream csv(csv_file.c_str());
	if (is_empty(csv))
		throw std::range_error("Empty csv File");
}

BitcoinExchange::BitcoinExchange(std::string csv_file) : __csv_file(csv_file.c_str()), __btree()
{
	std::string line;
	std::string date;
	std::string value;
	double price;

	__parse_csv(csv_file);
	std::ifstream csv(csv_file.c_str());
	std::getline(csv, line);
	while (std::getline(csv, line))
	{
		std::stringstream ss(line);
		std::getline(ss, date, ',');
		ss >> price;
		__btree[date] = price;
	}
	for (std::map<std::string, float>::iterator it = __btree.begin(); it != __btree.end(); it++)
	{
		date = it->first;
		price = it->second;
	}
}

BitcoinExchange::~BitcoinExchange()
{
	__csv_file.close();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &lv)
{
	if (&lv != this)
		*this = lv;
}

std::map<std::string, float> BitcoinExchange::getTree() const
{
	return (this->__btree);
}

float	BitcoinExchange::getBtcValue(std::string &date)
{
	std::map<std::string, float>::const_iterator it = __btree.find(date);
	if (it == __btree.end())
	{
		std::map<std::string, float>::const_iterator lower = __btree.lower_bound(date);
		if (lower == __btree.begin())
			throw std::range_error ("0 but btc didn't exist yet a this date");
		else
			--lower;
		return (lower->second);
	}
	else
		return (it->second);
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &rh)
{
	this->__btree = rh.getTree();
	return (*this);
}
