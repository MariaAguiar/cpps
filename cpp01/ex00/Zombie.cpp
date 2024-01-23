#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie( const std::string& myName )
{
	name = myName; //copy constructor da std::string
	announce();
}

void Zombie::announce()
{
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::~Zombie()
{
	std::cout << "RIP, " << name << ", henceforth forgotten" << std::endl;
}
