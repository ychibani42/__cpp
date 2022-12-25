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
        Fixed(const int);
        Fixed(const float);
        ~Fixed(void);
        Fixed		&operator=(const Fixed &newFixed);
        std::ofstream		&operator<<(const Fixed &newFixed);
        int			getRawBits( void ) const;
        void		setRawBits( int const raw );
		float		toFloat( void ) const;
		int			toInt( void ) const;
    
    private :
        static const int	__fract_part = 8;
        int					__fixed_value;
};

#endif