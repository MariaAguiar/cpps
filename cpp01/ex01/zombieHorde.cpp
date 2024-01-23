
#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string myName )
{
	Zombie* zombieHorde = new Zombie[N];
	for (int t = 0; t < N; t++)
		zombieHorde[t].setName( myName );
	return (zombieHorde);
}
