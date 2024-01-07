
#include "Zombie.hpp"

Zombie *newZombie( std::string myName )
{
	Zombie *newZombie = new Zombie( myName );
    if (newZombie)
		return (newZombie);
	return (NULL);
}
