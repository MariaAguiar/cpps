
#include "Zombie.h"

int main( void )
{
	randomChump( "Stack Dude" );
	Zombie* heap_zombie = newZombie( "Heap Gal" );
	if (heap_zombie)
		delete heap_zombie;
	return 1;
}