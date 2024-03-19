#include <iostream>
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main( void )
{
	{
		std::cout << "Scenario 1 (FAIL)" << std::endl;
		try
		{
			Bureaucrat b1("Pretty bad Bureaucrat", 150);
			ShrubberyCreationForm f1("An Unimportant Someone");
			// b1.downGrade();
			b1.signForm(f1);
			// f1.beSigned(b1);
			// b1.signForm(f1);
			f1.execute(b1);
		}
		// catch (const Bureaucrat::GradeTooHighException& e)
		catch (const std::exception &e)
		{
			std::cerr << "Error: " << e.what() << std::endl;
		}
	}
	std::cout << std::endl;
	{
		std::cout << "Scenario 2 (SUCCESS)" << std::endl;
		try
		{
			Bureaucrat b1("Stellar Bureaucrat", 2);
			ShrubberyCreationForm f1("Someone Important");
			// b1.upGrade();
			b1.signForm(f1);
			// f1.beSigned(b1);
			// b1.signForm(f1);
			f1.execute(b1);
			f1.execute(b1);
		}
		// catch (const Bureaucrat::GradeTooHighException& e)
		catch (const std::exception &e)
		{
			std::cerr << "Error: " << e.what() << std::endl;
		}
	}
	std::cout << std::endl;
	{
		{
		std::cout << "Scenario 3 (FAIL)" << std::endl;
		try
		{
			Bureaucrat b1("Pretty bad Bureaucrat", 150);
			RobotomyRequestForm f1("An Unimportant Someone");
			// b1.downGrade();
			b1.signForm(f1);
			// f1.beSigned(b1);
			// b1.signForm(f1);
			f1.execute(b1);
			f1.execute(b1);
		}
		// catch (const Bureaucrat::GradeTooHighException& e)
		catch (const std::exception &e)
		{
			std::cerr << "Error: " << e.what() << std::endl;
		}
	}
	std::cout << std::endl;
	{
		std::cout << "Scenario 4 (SUCCESS)" << std::endl;
		try
		{
			Bureaucrat b1("Stellar Bureaucrat", 2);
			RobotomyRequestForm f1("Someone Important");
			// b1.upGrade();
			b1.signForm(f1);
			// f1.beSigned(b1);
			// b1.signForm(f1);
			f1.execute(b1);
			f1.execute(b1);
		}
		// catch (const Bureaucrat::GradeTooHighException& e)
		catch (const std::exception &e)
		{
			std::cerr << "Error: " << e.what() << std::endl;
		}
	}
	std::cout << std::endl;
	}
		{
		std::cout << "Scenario 5 (FAIL)" << std::endl;
		try
		{
			Bureaucrat b1("Pretty bad Bureaucrat", 150);
			PresidentialPardonForm f1("An Unimportant Someone");
			// b1.downGrade();
			b1.signForm(f1);
			// f1.beSigned(b1);
			// b1.signForm(f1);
			f1.execute(b1);
			f1.execute(b1);
		}
		// catch (const Bureaucrat::GradeTooHighException& e)
		catch (const std::exception &e)
		{
			std::cerr << "Error: " << e.what() << std::endl;
		}
	}
	std::cout << std::endl;
	{
		std::cout << "Scenario 6 (SUCCESS)" << std::endl;
		try
		{
			Bureaucrat b1("Stellar Bureaucrat", 2);
			PresidentialPardonForm f1("Someone Important");
			// b1.upGrade();
			b1.signForm(f1);
			// f1.beSigned(b1);
			// b1.signForm(f1);
			f1.execute(b1);
			f1.execute(b1);
		}
		// catch (const Bureaucrat::GradeTooHighException& e)
		catch (const std::exception &e)
		{
			std::cerr << "Error: " << e.what() << std::endl;
		}
	}
	return 0;
}