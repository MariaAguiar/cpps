#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>
#include <string>
#include <exception>

class Bureaucrat;

class Form
{
	public:
		Form( const std::string nname, const int sgrade, const int egrade );
		Form( const Form& other );
		Form& operator=( const Form& other );
		~Form();

		const std::string getName() const;
		const int getSignGrade() const;
		const int getExecGrade() const;
		const bool getSign() const;

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
		Form();
		const std::string name;
		const int signGrade;
		const int execGrade;
		bool sign;
};

std::ostream& operator<<(std::ostream& os, const Form& obj);

#endif