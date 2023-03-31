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
#include <bits/stdc++.h>
#include <time.h>
#include <deque>
#include <algorithm>
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
		PmergeMe(std::vector<int>);
		PmergeMe(PmergeMe &);
		~PmergeMe();
		PmergeMe &operator=(const PmergeMe &);
		void	sort();
		void	MergeInsertionSort(std::deque<std::pair<int, int> > deque);
		void	MergeInsertionSort(std::vector<std::pair<int, int> > vector);
	private :
		std::deque<int> __deque;
		std::vector<int> __vector;
		double	__deque_t;
		double	__vector_t;
		std::vector<std::pair<int, int> > vec_pairs;
		std::deque<std::pair<int, int> > deq_pairs;
		bool	__is_odd;
		int		__odd_value;
};

#endif