#ifndef __SPAN_HPP__
# define __SPAN_HPP__

# include <vector>
# include <algorithm>
# include <iostream>

class Span
{
	public:
		Span(unsigned int n);
		Span(Span const & src);
		~Span(void);

		Span & operator=(Span const & rhs);

		void addNumber(int n);
		int shortestSpan(void) const;
		int longestSpan(void) const;
		void addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end);
	private :
		Span(void);
		std::vector<int> _v;
		unsigned int _n;
};

#endif