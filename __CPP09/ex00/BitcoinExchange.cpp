#include "BitcoinExchange.hpp"


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
		date = date + ' ';
		ss >> price;
		__btree[date] = price;
	}
	for (std::map<std::string, float>::iterator it = __btree.begin(); it != __btree.end(); it++)
	{
		date = it->first;
		price = it->second;
		std::cout << " date + price = :" << date << " " << price << std::endl;
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

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &rh)
{
	this->__btree = rh.getTree();
	return (*this);
}