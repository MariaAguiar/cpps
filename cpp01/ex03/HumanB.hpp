#ifndef HUMANB_HPP
# define HUMANB_HPP

#include <iostream>
#include <string>
#include "Weapon.hpp"

class HumanB
{
	public:
		HumanB( const std::string& myName );
		~HumanB();
		void attack();
		void setWeapon( Weapon &myWeapon );
	private:
		std::string _name;
		Weapon *_weapon;
};

#endif