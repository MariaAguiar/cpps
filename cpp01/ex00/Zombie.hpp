#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie
{
	public:
		Zombie( std::string myName );
		~Zombie();
	private:
		std::string name;
		void announce( void );
};

#endif