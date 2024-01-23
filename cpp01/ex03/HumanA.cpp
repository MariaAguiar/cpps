
#include "HumanA.hpp"

HumanA::HumanA( const std::string& myName, Weapon &myWeapon ) : _weapon(myWeapon)
{
	this->name = myName;
}

void HumanA::attack()
{
	std::cout << this->name << " attacks with their " << _weapon.getType() << std::endl;
}

HumanA::~HumanA(){}