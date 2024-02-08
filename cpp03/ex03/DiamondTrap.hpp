#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <iostream>
#include <string>

class DiamondTrap : public ScavTrap, public FragTrap
{
	public:
        DiamondTrap();
		DiamondTrap( std::string name );
		DiamondTrap( const DiamondTrap& other );
		DiamondTrap& operator=( const DiamondTrap& other );
		~DiamondTrap();

		void whoAmI();
	private:
        std::string Name;
};

#endif