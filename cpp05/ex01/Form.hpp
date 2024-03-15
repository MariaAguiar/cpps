#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>
#include <string>
#include <exception>
#include "Bureaucrat.hpp"

class Bureaucrat;
class Form
{
	public:
		Form( const std::string nname, const int sgrade, const int egrade );
		Form( const Form& other );
		Form& operator=( const Form& other );
		~Form();

		const std::string getName() const;
		int getSignGrade() const;
		int getExecGrade() const;
		bool getSign() const;

		void beSigned(const Bureaucrat &signer);
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

		class FormAlreadySignedException : public std::exception
		{
			public:
				const char *what(void) const throw();
		};
	private:
		Form();
		const std::string name;
		bool sign;
		const int signGrade;
		const int execGrade;
};

std::ostream& operator<<(std::ostream& os, const Form& obj);

#endif