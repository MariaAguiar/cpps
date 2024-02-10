#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal( std::string type )
{
	this->type = type;
	std::cout << "WrongAnimal: Parameterized constructor called" << std::endl;
};

WrongAnimal::WrongAnimal()
{
	std::cout << "WrongAnimal: Default constructor called" << std::endl;
};

WrongAnimal::WrongAnimal(const WrongAnimal& other)
{
	std::cout << "WrongAnimal: Copy constructor called" << std::endl;
	*this = other;
};

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other)
{
	std::cout << "WrongAnimal: Copy assignment operator called" << std::endl;
	if (this != &other) {
		this->type = other.type;
	}
	return *this;
};

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal: Destructor called" << std::endl;
};

void WrongAnimal::makeSound() const
{
	if (type.size() > 0)
		std::cout << type << ": ANIMAL SOOOOOUND!!!" << std::endl;
	else
		std::cout << "ANIMAL SOOOOOUND!!!" << std::endl;
};

std::string WrongAnimal::getType() const
{
	return (type);
};
