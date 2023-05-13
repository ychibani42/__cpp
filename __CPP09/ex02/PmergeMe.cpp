#include "PmergeMe.hpp"

void print_deq(const std::deque<int> &v)
{
	for (size_t i = 0; i < v.size(); ++i)
	{
		std::cout << v[i] << " ";
	}
	std::cout << std::endl;
}

void print_vec(const std::vector<int> &v)
{
	for (size_t i = 0; i < v.size(); ++i)
	{
		std::cout << v[i] << " ";
	}
	std::cout << std::endl;
}

void print_vec_pairs(const std::vector<std::pair<int, int> > &v)
{
	for (size_t i = 0; i < v.size(); ++i)
	{
		std::cout << " [" << v[i].first << ", " << v[i].second << "] | ";
	}
	std::cout << std::endl;
}

void print_seq_pairs(const std::deque<std::pair<int, int> > &v)
{
	for (size_t i = 0; i < v.size(); ++i)
	{
		std::cout << " [" << v[i].first << ", " << v[i].second << "]" << std::endl;
	}
	std::cout << std::endl;
}

PmergeMe::PmergeMe(std::vector<int> seq) : __deque(0), __vector(seq), vec_pairs(0), deq_pairs(0), __sorted_vector(0), __sorted_deque(0), __is_odd(false), __odd_value(0)
{
	std::cout << "Before: ";
	print_vec(seq);
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

PmergeMe::PmergeMe(PmergeMe &rhs)
{
	*this = rhs;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &rhs)
{
	this->__deque = rhs.__deque;
	this->__vector = rhs.__vector;
	this->vec_pairs = rhs.vec_pairs;
	this->deq_pairs = rhs.deq_pairs;

	return (*this);
}

bool SortBySec(const std::pair<int, int> &a, const std::pair<int, int> &b)
{
	return (a.second < b.second);
}

void PmergeMe::MergeInsertionSort(std::deque<std::pair<int, int> > &deq_pairs)
{
	size_t size = deq_pairs.size();
	for (size_t i = 0; i < size; i++)
	{
		if (deq_pairs[i].first > deq_pairs[i].second)
			std::swap(deq_pairs[i].first, deq_pairs[i].second);
	}
	std::sort(deq_pairs.begin(), deq_pairs.end(), SortBySec);
	for (size_t i = 0; i < size; i++)
		__sorted_deque.push_back(deq_pairs[i].second);
	for (size_t i = 0; i < size; i++)
	{
		std::deque<int>::iterator it = std::lower_bound(__sorted_deque.begin(), __sorted_deque.end(), deq_pairs[i].first);
		__sorted_deque.insert(it, deq_pairs[i].first);
	}
	if (__is_odd)
	{
		std::deque<int>::iterator it = std::lower_bound(__sorted_deque.begin(), __sorted_deque.end(), __odd_value);
		__sorted_deque.insert(it, __odd_value);
	}
}

void PmergeMe::MergeInsertionSort(std::vector<std::pair<int, int> > &vec_pairs)
{
	size_t size = vec_pairs.size();
	for (size_t i = 0; i < size; i++)
	{
		if (vec_pairs[i].first > vec_pairs[i].second)
			std::swap(vec_pairs[i].first, vec_pairs[i].second);
	}
	std::sort(vec_pairs.begin(), vec_pairs.end(), SortBySec);
	for (size_t i = 0; i < size; i++)
		__sorted_vector.push_back(vec_pairs[i].second);
	for (size_t i = 0; i < size; i++)
	{
		std::vector<int>::iterator it = std::lower_bound(__sorted_vector.begin(), __sorted_vector.end(), vec_pairs[i].first);
		__sorted_vector.insert(it, vec_pairs[i].first);
	}
	if (__is_odd)
	{
		std::vector<int>::iterator it = std::lower_bound(__sorted_vector.begin(), __sorted_vector.end(), __odd_value);
		__sorted_vector.insert(it, __odd_value);
	}
}

void PmergeMe::sort()
{
	{
		clock_t start = clock();
		MergeInsertionSort(vec_pairs);
		clock_t end = clock();
		std::cout << "After: ";
		print_vec(__sorted_vector);
		

		double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
		std::cout << "Time to process a range of " << __vector.size() << " elements with std::vector : " << std::fixed << std::setprecision(3) << time_taken * 1000 << " us " << std::endl;

	}
	{
		clock_t start = clock();
		MergeInsertionSort(deq_pairs);
		clock_t end = clock();

		double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
		std::cout << "Time to process a range of " << __deque.size() << " elements with std::deque : " << std::fixed << std::setprecision(3) << time_taken * 1000 << " us " << std::endl;
	}
}