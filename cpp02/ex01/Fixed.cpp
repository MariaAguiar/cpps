#include "Fixed.hpp"

Fixed::Fixed() :fixed_point(0)
{
	std::cout << "Default constructor called" << std::endl;
};

Fixed::Fixed(const int int_value)
{
	std::cout << "Int constructor called" << std::endl;
	this->fixed_point = int_value << bits;
};

Fixed::Fixed(const float float_value)
{
	std::cout << "Float constructor called" << std::endl;
	this->fixed_point = roundf(float_value * (1 << bits));
};

Fixed::Fixed(const Fixed& other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
};

Fixed& Fixed::operator=(const Fixed& other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other) {
		this->setRawBits( other.getRawBits() );
	}
	return *this;
};

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
};

int Fixed::getRawBits() const
{
	// std::cout << "getRawBits member function called" << std::endl;
	return this->fixed_point;
};

void Fixed::setRawBits( int const raw )
{
	this->fixed_point = raw;
};

float Fixed::toFloat() const
{
	return float(this->fixed_point / (1.0 * (1 << bits)));
};

int Fixed::toInt() const
{
	return (this->fixed_point >> bits);
};

std::ostream &operator<<(std::ostream &os, const Fixed &fixed)
{
	os << fixed.toFloat();
	return (os);
}
