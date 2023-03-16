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
#include <map>

class BitcoinExchange
{
	public :
		BitcoinExchange();
		~BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &);
		std::map<std::string , float> getTree() const;
		BitcoinExchange &operator=(const BitcoinExchange &rh);
	private :
		std::map<std::string , float> __btree;
};

#endif