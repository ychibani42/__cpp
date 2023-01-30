#include "Array.hpp"

#include <iostream>
#include "Array.hpp"
#include <cstdlib>
#include <ctime>


#define SIZE 10

int main(int, char**)
{
	Array<int> empty(0);
    Array<int> numbers(SIZE);
    int* tab = new int[SIZE];
    srand(time(NULL));

    for (int i = 0; i < SIZE; i++)
    {
        const int value = rand();
        numbers[i] = value;
        tab[i] = value;
    }
   for (int i = 0; i < SIZE; i++)
    {
        std::cout	<< "Array[" << i << "] is " << numbers[i]
					<< ", Tab[" << i << "] is " << tab[i] << std::endl;
    } 
	// try assignment operator test
    {
		std::cout << std::endl;
        Array<int> tmp = numbers;
    	for (int i = 0; i < SIZE; i++)
        std::cout	<< "tmp[" << i << "] is " << tmp[i] << std::endl;
		std::cout << tmp.size() << std::endl;
    }
    try
    {
        numbers[-23] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
	
    try
    {
        numbers[SIZE] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

	try
    {
        numbers[100000] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    delete [] tab;
    return 0;
}
