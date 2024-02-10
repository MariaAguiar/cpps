#include "Cure.hpp"

Cure::Cure()
{
	std::cout << "Cure: Default constructor called" << std::endl;
	type = "cure";
};

Cure::Cure(const Cure& other)
{
	std::cout << "Cure: Copy constructor called" << std::endl;
	*this = other;
};

Cure& Cure::operator=(const Cure& other)
{
	std::cout << "Cure: Copy assignment operator called" << std::endl;
	if (this != &other) {
		this->type = other.type;
	}
	return *this;
};

Cure::~Cure()
{
	std::cout << "Cure: Destructor called" << std::endl;
};

AMateria* Cure::clone() const
{
	return (new Cure);
};

void Cure::use(ICharacter& target)
{
	if (type == "cure")
		std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
};
