#include "Character.hpp"

Character::Character()
{
	std::cout << "Character: Default constructor called" << std::endl;
	name = "";
	index = 0;
	unusedIndex = 0;
	for (int i = 0; i < 4; i++)
	{
		materias[i] = NULL;
		unused[i] = NULL;
	}
};

Character::Character(std::string const &name)
{
	std::cout << "Character: Parameterized constructor called" << std::endl;
	this->name = name;
	index = 0;
	unusedIndex = 0;
	for (int i = 0; i < 4; i++)
	{
		materias[i] = NULL;
		unused[i] = NULL;
	}
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
		for(int i = 0; i <= this->index; i++)
		{
			if (this->materias[i])
				delete this->materias[i];
		}
		for(int i = 0; i <= other.index; i++)
			this->materias[i] = other.materias[i];
		for(int i = 0; i <= this->unusedIndex; i++)
			delete this->unused[i];
		for(int i = 0; i <= other.unusedIndex; i++)
			this->unused[i] = other.unused[i];
		this->index = other.index;
	}
	return *this;
};

Character::~Character()
{
	std::cout << "Character: Destructor called" << std::endl;
	for(int i = 0; i <= this->index; i++)
	{
		if(this->materias[i])
			delete this->materias[i];
	}
	for(int i = 0; i <= this->unusedIndex; i++)
		delete this->unused[i];
};

std::string const & Character::getName() const
{
	return (name);
};

void Character::equip(AMateria* m)
{
	if (!materias[index])
	{
		materias[index] = m;
		index++;
	}
};

void Character::unequip(int idx)
{
	if (materias[idx])
	{
		unused[unusedIndex] = materias[idx];
		unusedIndex++;
		materias[idx] = 0;
	}
};

void Character::use(int idx, ICharacter& target)
{
	if (materias[idx])
	{
		materias[idx]->use(target);
	}
};
