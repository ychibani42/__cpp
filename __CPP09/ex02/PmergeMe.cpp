#include "PmergeMe.hpp"

void print_deq(const std::deque<int>& v) {
    for (size_t i = 0; i < v.size(); ++i) {
        std::cout << v[i] << " ";
    }
    std::cout << std::endl;
}

void print_vec(const std::vector<int>& v) {
    for (size_t i = 0; i < v.size(); ++i) {
        std::cout << v[i] << " ";
    }
    std::cout << std::endl;
}

void print_vec_pairs(const std::vector<std::pair<int, int> >& v) {
    for (size_t i = 0; i < v.size(); ++i) {
		std::cout << " [" << v[i].first << ", " << v[i].second << "] | ";
    }
    std::cout << std::endl;
}

void print_seq_pairs(const std::deque<std::pair<int, int> >& v) {
    for (size_t i = 0; i < v.size(); ++i) {
		std::cout << " [" << v[i].first << ", " << v[i].second << "] | ";
    }
    std::cout << std::endl;
}

PmergeMe::PmergeMe(std::vector<int> seq) : __deque(0), __vector(seq), __deque_t(0), __vector_t(0), vec_pairs(0), deq_pairs(0) , __is_odd(false), __odd_value(0) 
{
	std::deque<int> dt(seq.begin(), seq.end()); 
	__deque = dt;
	if (__deque.size() % 2 != 0)
	{
		__is_odd = true;
		__odd_value = __vector.back();
		__vector.pop_back();
		__deque.pop_back();
	}
	for (size_t i = 0; i < __vector.size(); i += 2)
		vec_pairs.push_back(std::make_pair(__vector[i], __vector[i + 1]));
	for (size_t i = 0; i < __deque.size(); i += 2)
		deq_pairs.push_back(std::make_pair(__deque[i], __deque[i + 1]));
}

PmergeMe::~PmergeMe() {}

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

void	PmergeMe::MergeInsertionSort(std::deque<std::pair<int, int> > deq_pairs)
{
	SortFirstPairsValue();
	SortPairs();
	InsertSort();
	print_seq_pairs(deq_pairs);
}

void	PmergeMe::MergeInsertionSort(std::vector<std::pair<int, int> > vec_pairs)
{
	print_vec_pairs(vec_pairs);
}

void	PmergeMe::sort()
{
	clock_t start = clock();
	MergeInsertionSort(vec_pairs);
	clock_t end = clock();

	double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
	std::cout << "Time to process a range of " << __vector.size() << " elements with std::vector : " << std::fixed << time_taken << std::setprecision(5) << " us " << std::endl;

	start = clock();
	MergeInsertionSort(deq_pairs);
	end = clock();

	time_taken = double(end - start) / double(CLOCKS_PER_SEC);
	std::cout << "Time to process a range of " << __deque.size() << " elements with std::deque : " << std::fixed << time_taken << std::setprecision(5) << " us " << std::endl;

// std::cout << "Time to process a range of " << __vector.size() << " elements with std::list : " << (long double)(end - start) / (long double)10000 << " us " << std::endl;
}

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