#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <iostream>

class Weapon
{
	public:
		Weapon( const std::string &newType );
		~Weapon();
		void setType( std::string newType );
		const std::string &getType();
	private:
		std::string type;
};

#endif
