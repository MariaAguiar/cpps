#include "Point.hpp"

Point::Point() : x(0), y(0)
{
	std::cout << "Default constructor called" << std::endl;
};

Point::Point( const Fixed& fixed_x, const Fixed& fixed_y ) : x(fixed_x), y(fixed_y) 
{
	std::cout << "Parameterized constructor called" << std::endl;
};

Point::Point(const Point& other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
};

Point& Point::operator=(const Point &)
{
	return (*this);
};

Point::~Point()
{
	std::cout << "Destructor called" << std::endl;
};

const Fixed Point::getX( void ) const
{
	return (x);
}

const Fixed Point::getY( void ) const
{
	return (y);
}
