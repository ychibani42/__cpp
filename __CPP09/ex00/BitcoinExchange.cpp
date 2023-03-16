#include "BitcoinExchange.hpp"


BitcoinExchange::BitcoinExchange() : __btree() {}
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