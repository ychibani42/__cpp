#include "PmergeMe.hpp"

int	is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (__TRUE);
	return (__FALSE);
}

int	nbr_check(std::string str)
{
	long	nbr;

	nbr = std::atol(str.c_str());
	if (str.size() > 11 || nbr > INT_MAX || nbr < INT_MIN)
		return (__FAILURE);
	return (__SUCCESS);
}

int	check_str(std::string str)
{
	int	i;
	int	start;

	i = 0;
	if (str.empty())
		return (__FAILURE);
	while (str[i])
	{
		while (str[i] == ' ')
			i++;
		if (!str[i])
			return (__FAILURE);
		start = i;
		if ((str[i] == '-') && is_digit(str[i + 1]))
			i++;
		while (str[i] && is_digit(str[i]))
			i++;
		if (str[i] != '\0' && str[i] != ' ')
			return (__FAILURE);
		if (nbr_check(str.substr(start, i - start)) == __FAILURE)
			return (__FAILURE);
	}
	return (__SUCCESS);
}

int parse(int ac, char **av, std::string &final_str)
{
	std::string str;
	for (int i = 1; i < ac; i++)
	{
		str += " ";
		str += av[i];
	}
	if (check_str(str) == __FAILURE)
		return (__FAILURE);
	final_str = str;
	return (__SUCCESS);
}

std::vector<int> fill_my_vector(std::string final_str)
{
	std::vector<int> arr;
	std::istringstream str(final_str);
	int	nb;

	while (str >> nb)
		arr.push_back(nb);
	return (arr);
}

int	main(int ac, char **av)
{
	std::string final_str;

	if ((ac < 2))
		return (std::cout << "usage : <./PmergeMe x1 x2 ... xn>" << std::endl, __FAILURE);
	if (parse(ac, av, final_str) == __FAILURE)
		return (std::cout << "parsing error" << std::endl, __FAILURE);
	std::vector<int> arr = fill_my_vector(final_str);
	PmergeMe MergeMe(arr);
	MergeMe.sort();
}