#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include <iostream>
#include <string>
#include <fstream>
#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
	public:
		ShrubberyCreationForm( const std::string target );
		ShrubberyCreationForm( const ShrubberyCreationForm& other );
		ShrubberyCreationForm& operator=( const ShrubberyCreationForm& other );
		~ShrubberyCreationForm();
		void execute( Bureaucrat const &executor ) const;
		const std::string &getTarget(void) const;
		class CouldNotOpenFileException : public std::exception
        {
            public:
                const char *what(void) const throw();
        };

	private:
		ShrubberyCreationForm();
		const std::string target;
};

#endif