#include "Animal.hpp"

Animal::Animal( std::string type )
{
	this->type = type;
	std::cout << "Animal: Parameterized constructor called" << std::endl;
};

Animal::Animal()
{
	std::cout << "Animal: Default constructor called" << std::endl;
};

Animal::Animal(const Animal& other)
{
	std::cout << "Animal: Copy constructor called" << std::endl;
	*this = other;
};

Animal& Animal::operator=(const Animal& other)
{
	std::cout << "Animal: Copy assignment operator called" << std::endl;
	if (this != &other) {
		this->type = other.type;
	}
	return *this;
};

Animal::~Animal()
{
	std::cout << "Animal: Destructor called" << std::endl;
};

void Animal::makeSound() const
{
	if (type.size() > 0)
		std::cout << type << ": ANIMAL SOOOOOUND!!!" << std::endl;
	else
		std::cout << "ANIMAL SOOOOOUND!!!" << std::endl;
};

std::string Animal::getType() const
{
	return (type);
}