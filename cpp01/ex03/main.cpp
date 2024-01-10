
#include <iostream>
#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

int main( void )
{
	{
	Weapon club = Weapon("Brute Honesty");
	HumanA bob("Bob", club);
	bob.attack();
	club.setType("Inappropriate Retorts");
	bob.attack();
	}
	{
	Weapon club = Weapon("Poutting");
	HumanB jim("Jim");
	// jim.setWeapon(club);
	jim.attack();
	jim.setWeapon(club);
	jim.attack();
	club.setType("Waving white flag");
	jim.attack();
	}
	return 0;
}