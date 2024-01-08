#include <iostream>
#include <sstream>
#include "Zombie.h"

int main( int ac, char **av )
{
	if (ac == 2)
	{
		int	i;
		std::stringstream ss(av[1]);
		ss >> i;
		if (ss.fail())
		{
			std::cout << "Invalid Argument" << std::endl;
			return (2);
		}
		Zombie* horde = zombieHorde( i, "Heap Soldier" );
		if (!horde)
			return (2);
		for (int t = 0; t < i; t++)
		{
			std::cout << t + 1 << ": ";
			horde[t].announce();
		}
		delete[] horde;
	}
	else
		std::cout << "Invalid Number of Arguments" << std::endl;
	return 1;
}