#ifndef __WHATEVER_HPP__
# define __WHATEVER_HPP__

#include <iostream>

template < typename T >

void    swap(T &x, T &y)
{
     T temp;

    temp = x;
    x = y;
    y = temp;
}

template < typename T >

T &min(T &x, T &y)
{
    return ((x > y) ? y : x);
}

template < typename T >

T &max(T &x, T &y)
{
    return ((x > y) ? x : y);
}

#endif
