#include "Ice.hpp"

Ice::Ice()
{
	std::cout << "Ice: Default constructor called" << std::endl;
	type = "ice";
};

Ice::Ice(const Ice& other)
{
	std::cout << "Ice: Copy constructor called" << std::endl;
	*this = other;
};

Ice& Ice::operator=(const Ice& other)
{
	std::cout << "Ice: Copy assignment operator called" << std::endl;
	if (this != &other) {
		this->type = other.type;
	}
	return *this;
};

Ice::~Ice()
{
	std::cout << "Ice: Destructor called" << std::endl;
};

AMateria* Ice::clone() const
{
	return (new Ice);
};

void Ice::use(ICharacter& target)
{
	if (type == "ice")
		std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
};
