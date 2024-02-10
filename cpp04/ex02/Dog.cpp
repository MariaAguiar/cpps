#include "Dog.hpp"

Dog::Dog()
{
	std::cout << "Dog: Default constructor called" << std::endl;
	type = "Dog";
	brain = new Brain();
};

Dog::Dog(const Dog& other) : Animal(), brain(NULL)
{
	std::cout << "Dog: Copy constructor called" << std::endl;
	*this = other;
};

Dog& Dog::operator=(const Dog& other)
{
	std::cout << "Dog: Copy assignment operator called" << std::endl;
	if (this != &other) {
		this->type = other.type;
		if (this->brain)
			delete this->brain;
		this->brain = new Brain (*other.brain);
	}
	return *this;
};

Dog::~Dog()
{
	std::cout << "Dog: Destructor called" << std::endl;
	if (this->brain)
		delete brain;
};

void Dog::makeSound() const
{
	std::cout << type << ": BARK BARK BARK BARK!!!" << std::endl;
};
