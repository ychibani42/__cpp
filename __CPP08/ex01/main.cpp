#include "Span.hpp"

int main(void)
{
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	std::vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	Span sp2 = Span(5);
	sp2.addNumber(v.begin(), v.end());
	std::cout << sp2.shortestSpan() << std::endl;
	std::cout << sp2.longestSpan() << std::endl;

	Span sp3 = Span(10000);
	std::vector<int> v2;
	for (int i = 0; i < 10000; i++)
		v2.push_back(i);
	sp3.addNumber(v2.begin(), v2.end());
	std::cout << sp3.shortestSpan() << std::endl;
	std::cout << sp3.longestSpan() << std::endl;
	return (0);
}