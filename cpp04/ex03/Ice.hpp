#ifndef Ice_HPP
# define Ice_HPP

#include <iostream>
#include "AMateria.hpp"
#include <string>

class Ice : public AMateria
{
	public:
		Ice();
		Ice( const Ice& other );
		Ice& operator=( const Ice& other );
		~Ice();

		AMateria *clone() const;
		void use(ICharacter& target);
};

#endif