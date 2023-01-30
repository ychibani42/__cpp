#include "MutantStack.hpp"

int main()
{
	{
		std::cout << "MUTANT STACK ITERATOR" << std::endl;
		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);
		std::cout << mstack.top() << std::endl;
		mstack.pop();
		std::cout << mstack.size() << std::endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		//[...]
		mstack.push(0);
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << "[" << *it << "]";
			++it;
		}
		std::cout << std::endl;
		std::stack<int> s(mstack);
	}

	{
		std::cout << std::endl;
		std::cout << "LIST ITERATOR" << std::endl;
		std::list<int> lst;
		lst.push_back(5);
		lst.push_back(17);
		std::cout << lst.back() << std::endl;
		lst.pop_back();
		std::cout << lst.size() << std::endl;
		lst.push_back(3);
		lst.push_back(5);
		lst.push_back(737);
		//[...]
		lst.push_back(0);
		std::list<int>::iterator it = lst.begin();
		std::list<int>::iterator ite = lst.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << "[" << *it << "]";
			++it;
		}
		std::cout << std::endl;
		std::list<int> s(lst);
	}

	{
		std::cout << std::endl;
		std::cout << "MUTANT STACK CPY" << std::endl;
		MutantStack<int> mstack;
		MutantStack<int> mstack2;
		mstack.push(5);
		mstack.push(17);
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		mstack.push(0);
		mstack2 = mstack;
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;
		std::cout << "origine" << std::endl;
		while (it != ite)
		{
			std::cout << "[" << *it << "]";
			++it;
		}
		std::cout << std::endl;
		it = mstack2.begin();
		ite = mstack2.end();
		++it;
		--it;
		std::cout << "cpy :" << std::endl;
		while (it != ite)
		{
			std::cout << "[" << *it << "]";
			++it;
		}
		std::cout << std::endl;
	}
	return 0;
}