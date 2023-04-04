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
		std::cout << std::endl;
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

PmergeMe::PmergeMe(std::vector<int> seq) : __deque(0), __vector(seq), vec_pairs(0), deq_pairs(0), __sorted_array(0), __is_odd(false), __odd_value(0)
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

int	PmergeMe::BinarySearch(int to_insert, int start, int end)
{
	while (start <= end)
	{
		int mid = start + (end - start) / 2;
		if (to_insert < __sorted_array[mid])
			end = mid - 1;
		else
			start = mid + 1;
	}
	return start;
}

void PmergeMe::MergeInsertionSort(std::deque<std::pair<int, int> > &deq_pairs)
{
	for (size_t i = 0; i < deq_pairs.size(); i++)
	{
		if (deq_pairs[i].first > deq_pairs[i].second)
			std::swap(deq_pairs[i].first, deq_pairs[i].second);
	}
	std::sort(deq_pairs.begin(), deq_pairs.end(), SortBySec);






	for (size_t i = 0; i < deq_pairs.size(); i++)
		__sorted_array.push_back(deq_pairs[i].second);



	print_seq_pairs(deq_pairs);
	// print_seq_pairs(deq_pairs);
	print_vec(__sorted_array);


	// std::cout << deq_pairs.size() << std::endl;
	for (size_t i = 1; i < deq_pairs.size(); i++)
	{
		int pos = BinarySearch(deq_pairs[i].first, 0, i - 1);
		for (int j = i; j > pos; j--)
		{
			__sorted_array[j] = __sorted_array[j - 1];
		}
		__sorted_array[pos] = deq_pairs[i].first;
	}
	print_vec(__sorted_array);
}

void PmergeMe::MergeInsertionSort(std::vector<std::pair<int, int> > &vec_pairs)
{
	for (size_t i = 0; i < vec_pairs.size(); i++)
	{
		if (vec_pairs[i].first > vec_pairs[i].second)
			std::swap(vec_pairs[i].first, vec_pairs[i].second);
	}
	std::sort(vec_pairs.begin(), vec_pairs.end(), SortBySec);


	for (size_t i = 0; i < vec_pairs.size(); i++)
		__sorted_array.push_back(vec_pairs[i].second);

	for (size_t i = 1; i < vec_pairs.size(); i++)
	{
		std::vector<int>::iterator it = std::lower_bound(__sorted_array.begin(), __sorted_array.end(), vec_pairs[i].second);
		__sorted_array.insert(it, vec_pairs[i].first);
	}
	print_vec(__sorted_array);
	// print_vec(__sorted_array);
}

void PmergeMe::sort()
{
	{
		clock_t start = clock();
		MergeInsertionSort(vec_pairs);
		clock_t end = clock();

		double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
		std::cout << "Time to process a range of " << __vector.size() << " elements with std::vector : " << std::fixed << time_taken << std::setprecision(5) << " us " << std::endl;

	}
	{
		clock_t start = clock();
		MergeInsertionSort(vec_pairs);
		clock_t end = clock();

		double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
		std::cout << "Time to process a range of " << __deque.size() << " elements with std::deque : " << std::fixed << time_taken << std::setprecision(5) << " us " << std::endl;
	}
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