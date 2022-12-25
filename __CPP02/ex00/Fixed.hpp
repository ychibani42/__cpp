#ifndef __FIXED_HPP__
# define __FIXED_HPP__

# define    __SUCCESS 1
# define    __FAILURE 0

# include <iostream>

class   Fixed
{
    public :
        Fixed(void);
        Fixed(Fixed &t);
        ~Fixed(void);
        Fixed &operator=(const Fixed &newFixed);
        int getRawBits( void ) const;
        void setRawBits( int const raw );
    
    private :
        int __fixed_value;
        static const int __fract_part = 8;
};

#endif