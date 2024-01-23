#ifndef HUMANA_HPP
# define HUMANA_HPP

#include "Weapon.hpp"
#include <iostream>
#include <string>

class HumanA
{
	public:
		HumanA( const std::string& myName, Weapon &myWeapon );
		~HumanA();
		void attack();
	private:
		std::string name;
		Weapon& _weapon;
};

#endif