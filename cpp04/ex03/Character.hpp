#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include <iostream>
#include "AMateria.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "ICharacter.hpp"
#include <string>

#define BAGSIZE 5

class Character : public ICharacter
{
	private:
		std::string name;
		AMateria *materias[4];
		int index;
		AMateria *unused[BAGSIZE];
		int unusedIndex;
		int used;

	public:
		Character();
		Character(std::string const &name);
		Character( const Character& other );
		Character& operator=( const Character& other );
		~Character();

		std::string const & getName() const;
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);
};

#endif