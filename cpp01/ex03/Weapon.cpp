
#include "Weapon.hpp"

Weapon::Weapon( const std::string &myType )
{
	this->type = myType;
}

const std::string& Weapon::getType() const
{
	return (this->type);
}

void Weapon::setType( const std::string& newType )
{
	this->type = newType;
}

Weapon::~Weapon(){}