#include <iostream>
#include "Bureaucrat.hpp"

int main( void )
{
	{
		try
		{
			Bureaucrat b1("Pretty bad Bureaucrat", 149);	
			b1.downGrade();
			std::cout << "Updated" << std::endl;
			b1.downGrade();
		}
		catch (const Bureaucrat::GradeTooLowException& e)
		{
			std::cerr << "Error: " << e.what() << std::endl;
		}
	}
	{
		try
		{
			Bureaucrat b1("Stellar Bureaucrat", 2);
			b1.upGrade();
			std::cout << "Updated" << std::endl;
			b1.upGrade();
		}
		catch (const Bureaucrat::GradeTooHighException& e)
		{
			std::cerr << "Error: " << e.what() << std::endl;
		}
	}
	return 0;
}