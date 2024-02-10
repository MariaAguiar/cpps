#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain: Default constructor called" << std::endl;
	ideas[0] = "FOOOOOD!";
};

Brain::Brain(const Brain& other)
{
	std::cout << "Brain: Copy constructor called" << std::endl;
	*this = other;
};

Brain& Brain::operator=(const Brain& other)
{
	std::cout << "Brain: Copy assignment operator called" << std::endl;
	if (this != &other) {
		for(int i = 0; i <= 100; i++)
		{
			if (this->ideas[i].size() > 0)
				this->ideas[i] = other.ideas[i];
			else
				break ;
		}
	}
	return *this;
};

Brain::~Brain()
{
	std::cout << "Brain: Destructor called" << std::endl;
};
