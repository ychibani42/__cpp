#ifndef __ITER_HPP__
# define __ITER_HPP__

#include <iostream>

template <typename T>

void iter(T *t, int size, void (*f)(T const &))
{
    if (!f || !size || !t)
        return ;
    for (int i = 0; i < size; i++)
        f(t[i]);
}

#endif