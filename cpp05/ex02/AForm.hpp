#ifndef AFORM_HPP
# define AFORM_HPP

#include <iostream>
#include <string>
#include <exception>

class Bureaucrat;

class AForm
{
	public:
		AForm( const std::string nname, const int sgrade, const int egrade );
		AForm( const AForm& other );
		AForm& operator=( const AForm& other );
		virtual ~AForm();

		const std::string getName() const;
		const int getSignGrade() const;
		const int getExecGrade() const;
		const bool getSign() const;

		virtual void execute(Bureaucrat const & executor) const = 0;

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
		AForm();
		const std::string name;
		const int signGrade;
		const int execGrade;
		bool sign;
};

std::ostream& operator<<(std::ostream& os, const AForm& obj);

#endif