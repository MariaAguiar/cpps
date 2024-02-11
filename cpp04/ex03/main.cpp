#include "AMateria.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

int main()
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter* me = new Character("me");
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	for (int i = 0; i <= 11; i++)
	{
		tmp = src->createMateria("ice");
		me->equip(tmp);
	}
	for (int i = 3; i <= 4; i++)
		me->unequip(i);
	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(-1, *bob);
	delete bob;
	delete me;
	delete src;
	return 0;
}