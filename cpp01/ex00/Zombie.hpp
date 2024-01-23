#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie
{
	public:
		Zombie( const std::string& myName );
		~Zombie();

		void announce( void );
	private:
		std::string name;
};

#endif