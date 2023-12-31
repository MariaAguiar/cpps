#ifndef HUMANB_HPP
# define HUMANB_HPP

#include <iostream>
#include <string>
#include "Weapon.hpp"

class HumanB
{
	public:
		HumanB( std::string myName );
		~HumanB();
		void attack();
		void setWeapon( Weapon &myWeapon );
	private:
		std::string name;
		Weapon *weapon;
};

#endif