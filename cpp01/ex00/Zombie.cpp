#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie( std::string myName )
{
	this->name = myName;
	Zombie::announce();
}

void Zombie::announce()
{
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::~Zombie()
{
	std::cout << "RIP, " << this->name << ", henceforth forgotten" << std::endl;
}
