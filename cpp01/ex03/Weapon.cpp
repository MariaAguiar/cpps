
#include "Weapon.hpp"

Weapon::Weapon( const std::string &myType )
{
	this->type = myType;
}

const std::string &Weapon::getType()
{
	return (this->type);
}

void Weapon::setType( std::string newType )
{
	this->type = newType;
}

Weapon::~Weapon(){}