#ifndef Intern_HPP
# define Intern_HPP

#include <iostream>
#include <string>
#include <exception>
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class ShrubberyCreationForm;
class RobotomyRequestForm;
class PresidentialPardonForm;

class Intern
{
	private:
		static AForm *(*formConstructors[3])(const std::string &target);
	
	public:
		Intern();
		Intern( const Intern& other);
		Intern& operator=( const Intern& );
		~Intern();

		AForm *makeForm( const std::string form, const std::string target );
		class FormDoesNotExist : public std::exception
        {
            public:
                const char *what(void) const throw();
        };
};

#endif