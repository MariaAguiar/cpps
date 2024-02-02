#include <iostream>
#include "Fixed.hpp"

int main( void ) {
	Fixed a;
	Fixed b( a );
	Fixed c;
	c = b;

	// fixed a() -> Fixed::Fixed() 
	// fixed b(a) -> Fixed::Fixed(const Fixed& other) (+ Fixed& Fixed::operator=(const Fixed& other))
	// fixed c() -> Fixed::Fixed() 
	// c = a; -> Fixed& Fixed::operator=(const Fixed& other)

	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;
	return 0;
}