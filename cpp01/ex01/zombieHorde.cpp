
#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string myName )
{
	Zombie* zombieHorde = new Zombie[N];
	if (zombieHorde)
	{
		for (int t = 0; t < N; t++)
			zombieHorde[t].setName( myName );
		 return (zombieHorde);
	}
	return (NULL);
}
