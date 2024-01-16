#ifndef HARL_HPP
# define HARL_HPP

#include <iostream>
#include <string>

class Harl
{
	public:
		Harl();
		void complain( std::string level );
		~Harl();
	private:
		void debug( void );
		void info( void );
		void warning( void );
		void error( void );
		void invalidComplaint(void);
};

#endif