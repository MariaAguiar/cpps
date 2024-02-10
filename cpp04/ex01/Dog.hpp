#ifndef DOG_HPP
# define DOG_HPP

#include <iostream>
#include "Animal.hpp"
#include "Brain.hpp"
#include <string>

class Dog : public Animal
{
	public:
		Dog();
		Dog( const Dog& other );
		Dog& operator=( const Dog& other );
		~Dog();

		void makeSound() const;
	private:
		Brain *brain;
};

#endif