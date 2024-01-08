
#include "HumanA.hpp"

HumanA::HumanA( std::string myName, Weapon &myWeapon )
{
	this->name = myName;
	this->weapon = &myWeapon;
}

void HumanA::attack()
{
	std::cout << this->name << " attacks with their " << weapon->getType() << std::endl;
}

HumanA::~HumanA(){}