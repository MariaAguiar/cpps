#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <string>
#include <cmath>

class Fixed
{
	public:
		Fixed();
		Fixed( const int int_value );
		Fixed( const float float_value );
		Fixed( const Fixed& other );
		Fixed &operator=( const Fixed &other );
		~Fixed();

		int getRawBits( void ) const;
		void setRawBits( int const raw );

		float toFloat( void ) const;
		int toInt( void ) const;
	private:
		int fixed_point;
		static const int bits = 8;
};

std::ostream& operator<<(std::ostream& os, const Fixed& obj);

#endif