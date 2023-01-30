#include "Span.hpp"

Span::Span(unsigned int n) : _n(n) {}
Span::Span(Span const & src) : _n(src._n) {}
Span::~Span(void) {}
Span &Span::operator=(Span const & rhs) { if (this != &rhs) _n = rhs._n; return (*this);}

void Span::addNumber(int n)
{
	if (_v.size() < _n)
		_v.push_back(n);
	else
		throw std::exception();
}	

void Span::addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	if (end - begin > _n)
		throw std::exception();
	while (begin != end)
	{
		addNumber(*begin);
		begin++;
	}
}

int Span::shortestSpan(void) const
{
	if (_v.size() < 2)
		throw std::exception();
	std::vector<int> v(_v);
	std::sort(v.begin(), v.end());
	int min = v[1] - v[0];
	for (unsigned int i = 2; i < v.size(); i++)
	{
		if (v[i] - v[i - 1] < min)
			min = v[i] - v[i - 1];
	}
	return (min);
}

int Span::longestSpan(void) const
{
	if (_v.size() < 2)
		throw std::exception();
	std::vector<int> v(_v);
	std::sort(v.begin(), v.end());
	return (v[v.size() - 1] - v[0]);
}
