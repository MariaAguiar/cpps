#include "AMateria.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

int main()
{
	{
		std::cout << "\nPROVIDED TESTS:\n" << std::endl;
		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
		ICharacter* me = new Character("me");
		AMateria* tmp;
		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);
		ICharacter* bob = new Character("bob");
		me->use(0, *bob);
		me->use(1, *bob);
		delete bob;
		delete me;
		delete src;
	}

	ICharacter* bob = new Character("bob");
	IMateriaSource* src = new MateriaSource();
	ICharacter* me = new Character("me");
	AMateria* tmp;
	Ice *icy = new Ice();
	Cure *regen = new Cure();



	std::cout << "\n\nMATERIA LEARN TESTS:" << std::endl;


	std::cout << std::endl;
	tmp = src->createMateria("ice");

	std::cout << std::endl;
	src->learnMateria(icy);
	src->learnMateria(icy);

	std::cout << std::endl;
	src->learnMateria(regen);
	src->learnMateria(new Ice());
	src->learnMateria(new Ice());
	src->learnMateria(new Ice());
	src->learnMateria(icy);
	// delete icy;
	src->learnMateria(regen);
	// delete regen;

	std::cout << std::endl;
	me->use(0, *bob);



	std::cout << "\n\nEQUIP TESTS:" << std::endl;


	std::cout << std::endl;
	for (int i = 0; i <= 9; i++)
	{
		tmp = src->createMateria("ice");
		me->equip(tmp);
		me->equip(tmp);
	}
	std::cout << std::endl;
	


	std::cout << "\n\nUNEQUIP TESTS:" << std::endl;

	std::cout << std::endl;
	for (int i = 2; i <= 4; i++)
		me->unequip(i);
	std::cout << std::endl;
	me->unequip(1);

	std::cout << std::endl;
	tmp = src->createMateria("cure");
	me->equip(tmp);
	tmp = src->createMateria("ice");
	me->equip(tmp);



	std::cout << "\n\nUSE TESTS:" << std::endl;


	std::cout << std::endl;
	me->use(0, *bob);
	me->use(1, *bob);
	me->use(2, *bob);
	me->use(4, *bob);
	std::cout << std::endl;

	delete bob;
	delete me;
	delete src;
	return 0;
}