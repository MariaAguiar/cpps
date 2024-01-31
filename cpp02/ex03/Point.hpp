#ifndef POINT_HPP
# define POINT_HPP

#include <iostream>
#include <string>
#include <cmath>
#include "Fixed.hpp"

class Point
{
	public:
		Point();
		Point( const Fixed& x, const Fixed& y );
		Point( const Point& other );
		Point &operator=( const Point & );
		~Point();
		const Fixed getX() const;
		const Fixed getY() const;
	private:
		const Fixed x;
		const Fixed y;
};

#endif