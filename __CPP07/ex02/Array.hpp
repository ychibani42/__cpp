#ifndef __ARRAY_HPP__
# define __ARRAY_HPP__

#include <cstddef>
#include <iostream>

template<typename T>

class Array
{
    public :
		Array();
		Array(unsigned int n) : __size(n) { __array = new T[n]; };
		Array(Array const & src) { *this = src; };
		Array &operator=(Array const & src) { __size = src.__size; __array = new T[__size]; for (int i = 0; i < __size; i++) __array[i] = src.__array[i]; return *this; };
		T &operator[](int i) const {  if (i < 0 || i >= __size) throw std::exception(); return __array[i]; };
		int size() const { return __size; };
		~Array() { delete [] __array; };
    private :
        T* __array;
        int __size;

};


#endif