#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	std::cout << "MateriaSource: Default constructor called" << std::endl;
	index = 0;
};

MateriaSource::MateriaSource(const MateriaSource& other)
{
	std::cout << "MateriaSource: Copy constructor called" << std::endl;
	*this = other;
};

MateriaSource& MateriaSource::operator=(const MateriaSource& other)
{
	std::cout << "MateriaSource: Copy assignment operator called" << std::endl;
	if (this != &other) {
		this->index = other.index;
	}
	return *this;
};

MateriaSource::~MateriaSource()
{
	std::cout << "MateriaSource: Destructor called" << std::endl;
	for(int i = 0; i < index; i++)
		delete learned[i];
};

void MateriaSource::learnMateria(AMateria* materia)
{
	if (index < 4)
	{
		learned[index] = materia;
		index++;
	}
	else
		std::cout << "Maximum number of learned materia reached" << std::endl;
};

AMateria* MateriaSource::createMateria(std::string const & type)
{
	for(int i = 0; i < index; i++)
	{
		if (learned[i]->getType() == type)
		{
			std::cout << type << std::endl;
			AMateria *newMat = learned[i]->clone();
			return newMat;
		}
	}
	std::cout << "Tried to create unlearned Materia" << std::endl;
	return (0);
};
