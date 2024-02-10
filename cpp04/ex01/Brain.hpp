#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <iostream>
#include "Animal.hpp"
#include <string>

class Brain
{
	public:
		Brain();
		Brain( const Brain& other );
		Brain& operator=( const Brain& other );
		~Brain();
	private:
		std::string ideas[100];
};

#endif