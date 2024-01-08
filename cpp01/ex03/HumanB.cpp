
#include "HumanB.hpp"

HumanB::HumanB( std::string myName )
{
	this->name = myName;
}

void HumanB::setWeapon( Weapon &myWeapon )
{
	this->weapon = &myWeapon;
}

void HumanB::attack()
{
	std::cout << this->name << " attacks with their " << weapon->getType() << std::endl;
}

HumanB::~HumanB(){}
