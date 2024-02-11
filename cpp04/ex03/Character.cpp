#include "Character.hpp"

Character::Character()
{
	std::cout << "Character: Default constructor called" << std::endl;
	name = "";
	index = 0;
	unusedIndex = 0;
	for (int i = 0; i < 4; i++)
		materias[i] = NULL;
	for (int i = 0; i < BAGSIZE; i++)
		unused[i] = NULL;
};

Character::Character(std::string const &name)
{
	std::cout << "Character: Parameterized constructor called" << std::endl;
	this->name = name;
	index = 0;
	unusedIndex = 0;
	for (int i = 0; i < 4; i++)
		materias[i] = NULL;
	for (int i = 0; i < BAGSIZE; i++)
		unused[i] = NULL;
};

Character::Character(const Character& other)
{
	std::cout << "Character: Copy constructor called" << std::endl;
	*this = other;
};

Character& Character::operator=(const Character& other)
{
	std::cout << "Character: Copy assignment operator called" << std::endl;
	if (this != &other) {
		this->name = other.name;
		for(int i = 0; i < 4; i++)
		{
			if (this->materias[i])
				delete this->materias[i];
		}
		for(int i = 0; i < other.index; i++)
			this->materias[i] = other.materias[i];
		for(int i = 0; i < BAGSIZE; i++)
		{
			if (this->unused[i])
				delete this->unused[i];
		}
		for(int i = 0; i < other.unusedIndex; i++)
			this->unused[i] = other.unused[i];
		this->index = other.index;
	}
	return *this;
};

Character::~Character()
{
	std::cout << "Character: Destructor called" << std::endl;
	for(int i = 0; i < 4; i++)
	{
		if (materias[i])
			delete materias[i];
	}
	for(int i = 0; i < BAGSIZE; i++)
	{
		if (unused[i])
			delete unused[i];
	}
};

std::string const & Character::getName() const
{
	return (name);
};

void Character::equip(AMateria* m)
{
	if (!m)
		return ;
	if (index < 4 && !materias[index])
	{
		for(int i = 0; i < 4; i++)
		{
			if (materias[i] == m)
			{
				std::cout << "Materia already equiped" << std::endl;
				return ;
			}
		}
		materias[index] = m;
		index++;
	}
	else if (index >= 4 && materias[index])
	{
		std::cout << "Materia slots already filled. Materia will be sent to bag." << std::endl;
		if (unusedIndex > BAGSIZE)
			unusedIndex = 0;
		if (this->unused[unusedIndex])
		{
			std::cout << "Bag is full. Discarding oldest materia..." << std::endl;
			delete this->unused[unusedIndex];
		}
		unused[unusedIndex] = m;
		std::cout << "The new materia was sent to the bag." << std::endl;
	}
};

void Character::unequip(int idx)
{
	if (idx > 0 && idx < 4 && materias[idx])
	{
		if (unusedIndex > BAGSIZE)
			unusedIndex = 0;
		if (this->unused[unusedIndex])
		{
			std::cout << "Bag is full. Discarding oldest materia..." << std::endl;
			delete this->unused[unusedIndex];
		}
		unused[unusedIndex] = materias[idx];
		unusedIndex++;
		materias[idx] = 0;
	}
	else
		std::cout << "Materia cannot be unequiped" << std::endl;
};

void Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx > index)
	{
		std::cout << "Invalid Index" << std::endl;
		return ;
	}
	if (materias[idx])
	{
		materias[idx]->use(target);
	}
	else
		std::cout << "Materia not usable" << std::endl;
};
