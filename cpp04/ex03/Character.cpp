#include "Character.hpp"

Character::Character()
{
	// std::cout << "Character: Default constructor called" << std::endl;
	name = "";
	index = 0;
	unusedIndex = 0;
	used = BAGSIZE + 1;
	for (int i = 0; i < 4; i++)
		materias[i] = NULL;
	for (int i = 0; i < BAGSIZE; i++)
		unused[i] = NULL;
};

Character::Character(std::string const &name)
{
	// std::cout << "Character: Parameterized constructor called" << std::endl;
	this->name = name;
	index = 0;
	unusedIndex = 0;
	used = BAGSIZE + 1;
	for (int i = 0; i < 4; i++)
		materias[i] = NULL;
	for (int i = 0; i < BAGSIZE; i++)
		unused[i] = NULL;
};

Character::Character(const Character& other)
{
	// std::cout << "Character: Copy constructor called" << std::endl;
	*this = other;
};

Character& Character::operator=(const Character& other)
{
	// std::cout << "Character: Copy assignment operator called" << std::endl;
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
		this->unusedIndex = other.unusedIndex;
		this->used = other.used;
	}
	return *this;
};

Character::~Character()
{
	// std::cout << "Character: Destructor called" << std::endl;
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
	int i = 0;

	if (!m)
		return ;
	for(i = 0; i < 4; i++)
	{
		if (materias[i] && materias[i] != m)
			continue;
		else
			break ;
	}
	if (i < 4 && !materias[i])
	{
		materias[i] = m;
		index++;
		std::cout << "Materia successfully equiped" << std::endl;
	}
	else if (i < 4 && materias[i] && materias[i] == m)
		std::cout << "Materia already equiped" << std::endl;
	else
	{
		for(i = 0; i < BAGSIZE; i++)
		{
			if (unused[i] && unused[i] == m)
			{
				std::cout << "Materia already in bag" << std::endl;
				return ;
			}
		}
		std::cout << "Materia slots already filled. Materia will be sent to the bag" << std::endl;
		if (unusedIndex >= BAGSIZE && used >= BAGSIZE)
			used = 0;
		if (used < BAGSIZE)
		{
			std::cout << "Bag is full. Discarding oldest materia..." << std::endl;
			delete unused[used];
			unused[used] = m;
			used++;
		}	
		else
		{
			unused[unusedIndex] = m;
			unusedIndex++;
		}
		std::cout << "The new materia was sent to the bag" << std::endl;
	}
};

void Character::unequip(int idx)
{
	int toUse = 0;
	if (unusedIndex >= BAGSIZE && used >= BAGSIZE)
		used = 0;
	if (idx > 0 && idx < 4 && materias[idx])
	{
		if (unusedIndex >= BAGSIZE)
			toUse = used;
		else
			toUse = unusedIndex;
		if (this->unused[toUse])
		{
			std::cout << "Bag is full. Discarding oldest materia..." << std::endl;
			delete this->unused[toUse];
		}
		unused[toUse] = materias[idx];
		std::cout << "The materia was sent to the bag" << std::endl;
		if (unusedIndex >= BAGSIZE)
			used++;
		else
			unusedIndex++;
		materias[idx] = 0;
		std::cout << "Slot " << idx << " is available" << std::endl;
	}
	else
		std::cout << "Materia cannot be unequiped" << std::endl;
};

void Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx > 3)
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
