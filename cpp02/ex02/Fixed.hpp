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

		bool operator>(const Fixed &other) const;
        bool operator<(const Fixed &other) const;
        bool operator>=(const Fixed &other) const;
        bool operator<=(const Fixed &other) const;
        bool operator==(const Fixed &other) const;
        bool operator!=(const Fixed &other) const;
        Fixed operator+(const Fixed &other) const;
        Fixed operator-(const Fixed &other) const;
        Fixed operator*(const Fixed &other) const;
        Fixed operator/(const Fixed &other) const;
        Fixed operator++();
        Fixed operator++(int);
        Fixed operator--();
        Fixed operator--(int);

		static Fixed& min(Fixed& first, Fixed& second);
		static Fixed& max(Fixed& first, Fixed& second);
		static const Fixed& min(const Fixed& first, const Fixed& second);
		static const Fixed& max(const Fixed& first, const Fixed& second);
	private:
		int fixed_point;
		static const int bits = 8;
};

std::ostream& operator<<(std::ostream& os, const Fixed& obj);

#endif