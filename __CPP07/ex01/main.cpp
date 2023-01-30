#include "iter.hpp"

void print_int(int const &i)
{
    std::cout << i;
}

struct Person
{
    std::string name;
    int age;
};

void    print_person(Person const &id)
{
    std::cout << id.name << " a " << id.age << " ans." << std::endl;
}

class Awesome
{
	public:
		Awesome( void ): _n( 42 ) { return ; }
		int get( void ) const { return this->_n; }
	private:
		int _n;
};

std::ostream &operator<<(std::ostream &o, Awesome const & rhs) 
{
	o << rhs.get();
	return o; 
}

template < typename T >

void print( T const & x ) 
{ 
	std::cout << x << std::endl; 
	return; 
}

int main() 
{
	int tab[] = { 0, 1, 2, 3, 4 };
	iter( tab, 5, print);
    std::cout << std::endl;
	int array[] = {0, 1, 2, 3, 4};
    iter(array, 5, print_int);
    std::cout << std::endl;
    Person Studs[] =  {{"Ychibani", 25}, {"Slatibarfast", 30}, {"Arthur", 35}};
    iter(Studs, 3, print_person);
	std::cout << std::endl;
    iter(array, 0, print_int);
	Awesome tab2[5];
	iter( tab2, 5, print);
	return 0; 
}
