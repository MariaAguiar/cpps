#include "AMateria.hpp"

AMateria::AMateria()
{
	// std::cout << "AMateria: Default constructor called" << std::endl;
	type = "";
};

AMateria::AMateria(const AMateria& other)
{
	// std::cout << "AMateria: Copy constructor called" << std::endl;
	*this = other;
};

AMateria& AMateria::operator=(const AMateria& other)
{
	// std::cout << "AMateria: Copy assignment operator called" << std::endl;
	if (this != &other) {
		this->type = other.type;
	}
	return *this;
};

AMateria::~AMateria()
{
	// std::cout << "AMateria: Destructor called" << std::endl;
};

std::string const & AMateria::getType() const
{
	return (type);
};

AMateria* AMateria::clone() const
{
	return 0;
};

void AMateria::use(ICharacter&) {};
