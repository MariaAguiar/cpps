
#include <sstream>
#include "Zombie.h"

int main( int ac, char **av )
{
	if (ac > 1)
	{
		int	i;
		std::stringstream ss(av[1]);
		ss >> i;
		if (ss.fail())
			return (2);
		Zombie* horde = zombieHorde( i, "Heap Soldier" );
		if (!horde)
			return (2);
		for (int t = 0; t < i; t++)
		{
			std::cout << t << ": ";
			horde[t].announce();
		}
		delete[] horde;
	}
	return 1;
}