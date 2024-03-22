#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <exception>
#include <cstdlib>
#include "AForm.hpp"

class AForm;
class Bureaucrat
{
	public:
		Bureaucrat( const std::string name, int grade );
		Bureaucrat( const Bureaucrat& other );
		Bureaucrat& operator=( const Bureaucrat& other );
		~Bureaucrat();

		const std::string getName() const;
		int getGrade() const;
		void upGrade();
		void downGrade();

		void signForm(const AForm &f);
		void executeForm(AForm const &form);
		class GradeTooHighException : public std::exception
        {
            public:
				const char *what(void) const throw();
        };

        class GradeTooLowException : public std::exception
        {
            public:
                const char *what(void) const throw();
        };
	private:
		Bureaucrat();
		const std::string name;
		int grade;
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& obj);

#endif