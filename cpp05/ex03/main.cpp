#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main( void )
{
	{
		std::cout << "Scenario 1 (FAIL)" << std::endl;
		AForm* rrf;
		try
		{
			Bureaucrat b1("Pretty Bad Bureaucrat", 1);
			Intern someRandomIntern;
			rrf = someRandomIntern.makeForm("RobotomyRequest", "Bender");
			b1.signForm(*rrf);
			b1.signForm(*rrf);
			b1.executeForm(*rrf);
		}
		catch (const std::exception &e)
		{
			std::cerr << "Error: " << e.what() << std::endl;
		}
		delete rrf;
	}
	std::cout << std::endl;
	{
		std::cout << "Scenario 2 (SUCCESS)" << std::endl;
		AForm* rrf;
		try
		{
			Bureaucrat b1("Stellar Bureaucrat", 1);
			Intern someRandomIntern;
			rrf = someRandomIntern.makeForm("RobotomyRequest", "Bender");
			b1.signForm(*rrf);
			b1.executeForm(*rrf);
		}
		catch (const std::exception &e)
		{
			std::cerr << "Error: " << e.what() << std::endl;
		}
		delete rrf;
	}
	return 0;
}