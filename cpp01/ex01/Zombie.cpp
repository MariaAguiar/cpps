#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie(){}

void Zombie::announce()
{
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName( std::string myName )
{
	this->name = myName;
}

Zombie::~Zombie()
{
	std::cout << "RIP, " << this->name << ", henceforth forgotten" << std::endl;
}
