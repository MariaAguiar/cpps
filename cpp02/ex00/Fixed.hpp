#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <string>

class Fixed
{
	public:
		Fixed();
		Fixed( const Fixed& other );
		Fixed &operator=( const Fixed &other );
		~Fixed();

		int getRawBits( void ) const;
		void setRawBits( int const raw );
	private:
		int fixed_point;
		static const int bits = 8;
};

#endif