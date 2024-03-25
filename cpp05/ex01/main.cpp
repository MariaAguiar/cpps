#include <iostream>
#include "Bureaucrat.hpp"

int main( void )
{
	{
		std::cout << "Scenario 1" << std::endl;
		try
		{
			Bureaucrat b1("Pretty bad Bureaucrat", 150);
			Form f1("Unimportant Form", 149);
			b1.upGrade();
			b1.signForm(f1);
			b1.signForm(f1);
			std::cout << "OK Here" << std::endl;
			f1.beSigned(b1);
		}
		// catch (const Bureaucrat::GradeTooHighException& e)
		catch (const std::exception &e)
		{
			std::cerr << "Error: " << e.what() << std::endl;
		}
	}
	std::cout << std::endl;
	{
		std::cout << "Scenario 2" << std::endl;
		try
		{
			Bureaucrat b1("Stellar Bureaucrat", 2);
			Form f1("Extremely Important Form", 1);
			b1.upGrade();
			b1.signForm(f1);
			std::cout << "OK Here" << std::endl;
			b1.signForm(f1);
			f1.beSigned(b1);
		}
		// catch (const Bureaucrat::GradeTooHighException& e)
		catch (const std::exception &e)
		{
			std::cerr << "Error: " << e.what() << std::endl;
		}
	}
	return 0;
}