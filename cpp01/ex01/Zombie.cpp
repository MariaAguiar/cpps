#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie(){}

void Zombie::announce()
{
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName( const std::string& myName )
{
	name = myName; //copy assignment da std::string;
}

Zombie::~Zombie()
{
	std::cout << "RIP, " << this->name << ", henceforth forgotten" << std::endl;
}
