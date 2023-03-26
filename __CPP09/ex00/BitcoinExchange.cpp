#include "BitcoinExchange.hpp"

void	print_tree(const std::map<std::string, float> &tree)
{
	for (std::map<std::string, float>::const_iterator it = tree.begin(); it != tree.end(); it++)
	{
		std::cout << "first == [" << it->first << "]" << std::endl;
		std::cout << "second == [" << it->second << "]" << std::endl;;
	}
}

BitcoinExchange::BitcoinExchange() : __btree() 
{
	std::ifstream csv("data.csv");
	std::string line;
	std::string date;
	std::string value;
	double price;

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

BitcoinExchange::~BitcoinExchange(){}

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
			throw ("Btc didn't exist at this date");
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