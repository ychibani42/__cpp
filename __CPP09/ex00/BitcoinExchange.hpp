/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychibani <ychibani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 15:11:06 by ychibani          #+#    #+#             */
/*   Updated: 2023/03/14 15:13:4 by ychibani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __SUCCESS
# define __SUCCESS 1
#endif

#ifndef __FAILURE
# define __FAILURE -1
#endif

#ifndef __BITCOINEXCHANGE_HPP__
# define __BITCOINEXCHANGE_HPP__

#include <iostream>
#include <cstring>
#include <string>
#include <fstream>
#include <sstream>
#include <sys/stat.h>
#include <climits>
#include <limits>
#include <map>
#include <cstdlib>

class BitcoinExchange
{
	public :
		BitcoinExchange();
		~BitcoinExchange();
		BitcoinExchange(std::string csv_file);
		BitcoinExchange(const BitcoinExchange &);
		std::map<std::string , float> getTree() const;
		BitcoinExchange &operator=(const BitcoinExchange &rh);
		float getBtcValue(std::string &date);
	private :
		std::ifstream __csv_file;
		void	__parse_csv(std::string csv_file);
		std::map<std::string , float> __btree;
};

int	check_date(std::string date);
int	check_value(std::string value);
bool is_empty(std::ifstream& pFile);
#endif