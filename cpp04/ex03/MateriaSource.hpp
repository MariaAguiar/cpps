#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

#include <iostream>
#include "AMateria.hpp"
#include "IMateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include <string>

class MateriaSource : public IMateriaSource
{
	private:
		AMateria *learned[4];
		int index;

	public:
		MateriaSource();
		MateriaSource( const MateriaSource& other );
		MateriaSource& operator=( const MateriaSource& other );
		~MateriaSource();

		void learnMateria(AMateria* materia);
		AMateria* createMateria(std::string const & type);
};

#endif