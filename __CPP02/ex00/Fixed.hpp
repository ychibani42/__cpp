/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychibani <ychibani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 13:28:43 by ychibani          #+#    #+#             */
/*   Updated: 2022/12/27 13:28:48 by ychibani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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