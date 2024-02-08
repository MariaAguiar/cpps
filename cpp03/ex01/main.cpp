#include <iostream>
#include "ScavTrap.hpp"

int main( void ) {
	ScavTrap player("Better Hero");
	std::cout << std::endl;
	player.attack("OP Monster");
	std::cout << std::endl;
	player.takeDamage(10);
	std::cout << std::endl;
	player.takeDamage(10);
	std::cout << std::endl;
	player.beRepaired(2);

	for (int i = 0; i <= 50; i++)
	{
		std::cout << std::endl;
		player.attack("OP Monster");
	}

	std::cout << std::endl;
	player.beRepaired(2);

	std::cout << std::endl;
	player.guardGate();
	
	return 0;
}