#ifndef __EASYFIND_HPP__
# define __EASYFIND_HPP__

# include <iostream>
# include <algorithm>
# include <vector>
# include <list>
# include <set>

class not_found : public std::exception
{
	public:
		virtual const char* what() const throw()
		{
			return ("Element not found :(");
		}
};

template <typename T>

typename T::iterator easyfind(T a, int to_cmp)
{
	typename T::iterator p = std::find(a.begin(), a.end(), to_cmp);
	for (p = a.begin(); p != a.end(); ++p)
	{
		if (*p == to_cmp)
		{
			std::cout << "Element found !" << std::endl;
			return (p);
		}
	}
	throw not_found();
}

#endif