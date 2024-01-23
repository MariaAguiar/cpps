
#include "HumanB.hpp"

HumanB::HumanB( const std::string& myName )
{
	this->_name = myName;
	this->_weapon = NULL;
}

void HumanB::setWeapon( Weapon& myWeapon )
{
	this->_weapon = &myWeapon;
}

void HumanB::attack()
{
	if (this->_weapon)
		std::cout << this->_name << " attacks with their " << _weapon->getType() << std::endl;
	else
		std::cout << this->_name << " is unarmed" << std::endl;
}

HumanB::~HumanB(){}
