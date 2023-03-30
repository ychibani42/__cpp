/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychibani <ychibani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 16:33:24 by ychibani          #+#    #+#             */
/*   Updated: 2023/03/27 13:35:24 by ychibani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __PMERGEME_HPP__
# define __PMERGEME_HPP__

#include <iostream>
#include <sstream>
#include <stdlib.h>
#include <string>
#include <vector>
#include <list>
#include <limits>
#include <climits>

# ifndef __SUCCESS
#  define __SUCCESS 1
# endif

# ifndef __FAILURE
#  define __FAILURE -1
# endif

# ifndef __TRUE
#  define __TRUE 1
# endif

# ifndef __FALSE
#  define __FALSE 0
# endif


class PmergeMe 
{
	public:
		PmergeMe();
		PmergeMe(PmergeMe &);
		~PmergeMe();
		PmergeMe &operator=(const PmergeMe &);
		void	sort();
		void	MergeInsertionSort(std::list<int> list);
		void	MergeInsertionSort(std::vector<int> vector);
	private :
		std::list<int> __list;
		std::vector<int> __vector;
		double	__list_t;
		double	__vector_t;
};

#endif