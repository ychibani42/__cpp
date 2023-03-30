#include "PmergeMe.hpp"

// PmergeMe::PmergeMe(std::vector<int> seq) : __list(seq), __vector(seq), __list_t(0), __vector_t(0)
// {
// 	MergeInsertionSort(__vector);
// 	MergeInsertionSort(__list);
// }

// PmergeMe::~PmergeMe() {}
// PmergeMe::PmergeMe(PmergeMe &rhs)
// {
// 	*this = rhs;
// }
// PmergeMe &PmergeMe::operator=(const PmergeMe &rhs)
// {
// 	this->__list = rhs.__list;
// 	this->__vector = rhs.__vector;
// 	return (*this);
// }

// void	PmergeMe::sort()
// {
// 	clock_t start = clock();

// 	std::cout << "Time to process a range of " << __list.size() << " elements with std::list :" << (float)clock() - start / CLOCKS_PER_SEC << " us " << std::endl;
// }

// void	PmergeMe::MergeInsertionSort(std::list<int> list)
// {
	// std::vector<int>::size_type middle = __list.size() / 2;
	// std::vector<int> left(__list.begin(), __list.begin() + middle);
	// std::vector<int> right(__list.begin() + middle, __list.begin());
	// if (list.end() - list.begin() < 2)
		// InsertSort(list);
	// else
	// {
		// MergeSort(list / 2);
		// std::merge()
	// }
// }

// void	PmergeMe::MergeInsertionSort(std::vector<int> vector)
// {

// }