#include <iostream>
#include "Point.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point);

int main( void )
{
	{
		const Point a(1, 1);
		const Point b(5, 5);
		const Point c(1, 10);
		const Point point(1, 2); 
		std::cout << (bsp(a, b, c, point) == 1 ? "True" : "False") << std::endl;
	}
}