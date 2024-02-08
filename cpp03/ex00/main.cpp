#include <iostream>
#include "ClapTrap.hpp"

int main( void ) {
	ClapTrap player("Zero to Hero");
	std::cout << std::endl;
	player.attack("OP Monster");
	std::cout << std::endl;
	player.takeDamage(10);
	std::cout << std::endl;
	player.takeDamage(10);
	std::cout << std::endl;
	player.beRepaired(2);

	for (int i = 0; i <= 10; i++)
	{
		std::cout << std::endl;
		player.attack("OP Monster");
	}

	std::cout << std::endl;
	player.beRepaired(2);
	
	return 0;
}