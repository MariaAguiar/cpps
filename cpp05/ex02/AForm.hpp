#ifndef AFORM_HPP
# define AFORM_HPP

#include <iostream>
#include <string>
#include <exception>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	public:
		AForm( const std::string nname, const int sgrade, const int egrade );
		AForm( const AForm& other );
		AForm& operator=( const AForm& other );
		virtual ~AForm();

		const std::string getName() const;
		int getSignGrade() const;
		int getExecGrade() const;
		bool getSign() const;

		void beSigned(const Bureaucrat &signer);
		void canExecute(const Bureaucrat& signer) const;
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
		class FormAlreadySignedException : public std::exception
		{
			public:
				const char *what(void) const throw();
		};
		 class FormNotSignedException : public std::exception
        {
            public:
                const char *what(void) const throw();
        };
	private:
		AForm();
		const std::string name;
		bool sign;
		const int signGrade;
		const int execGrade;
};

std::ostream& operator<<(std::ostream& os, const AForm& obj);

#endif