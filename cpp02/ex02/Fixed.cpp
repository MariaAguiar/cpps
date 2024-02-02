#include "Fixed.hpp"

Fixed::Fixed() :fixed_point(0)
{
	std::cout << "Default constructor called" << std::endl;
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



int Fixed::getRawBits() const
{
	std::cout << "getRawBits member function called" << std::endl;
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



bool Fixed::operator>(const Fixed &other) const
{
	return (this->fixed_point > other.fixed_point);
};

bool Fixed::operator<(const Fixed &other) const
{
	return (this->fixed_point < other.fixed_point);
};

bool Fixed::operator>=(const Fixed &other) const
{
	return (this->fixed_point >= other.fixed_point);
};

bool Fixed::operator<=(const Fixed &other) const
{
	return (this->fixed_point <= other.fixed_point);
};

bool Fixed::operator==(const Fixed &other) const
{
	return (this->fixed_point == other.fixed_point);
};

bool Fixed::operator!=(const Fixed &other) const
{
	return (this->fixed_point != other.fixed_point);
};



Fixed Fixed::operator+(const Fixed &other) const
{
	return (this->toFloat() + other.toFloat());
};

Fixed Fixed::operator-(const Fixed &other) const
{
	return (this->toFloat() - other.toFloat());
};

Fixed Fixed::operator*(const Fixed &other) const
{
	return (this->toFloat() * other.toFloat());
};

Fixed Fixed::operator/(const Fixed &other) const
{
	return (this->toFloat() / other.toFloat());
};



Fixed Fixed::operator++(int)
{
	Fixed copied(*this);

	this->fixed_point++;
	return (copied);
};

Fixed Fixed::operator++()
{
	++fixed_point;
	return (toFloat());
};

Fixed Fixed::operator--(int)
{
	Fixed copied(*this);

	this->fixed_point--;
	return (copied);
};

Fixed Fixed::operator--()
{
	--fixed_point;
	return (toFloat());
};


Fixed& Fixed::min(Fixed& first, Fixed& second)
{
	return ((first < second) ? first : second);
};

Fixed& Fixed::max(Fixed& first, Fixed& second)
{
	return ((first > second) ? first : second);
};

const Fixed& Fixed::min(const Fixed& first, const Fixed& second)
{
	return ((first < second) ? first : second);
};

const Fixed& Fixed::max(const Fixed& first, const Fixed& second)
{
	return ((first > second) ? first : second);
};


std::ostream &operator<<(std::ostream &os, const Fixed &fixed)
{
	os << fixed.toFloat();
	return (os);
}