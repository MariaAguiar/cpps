#include <iostream>
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main( void )
{
	try {
		Bureaucrat j( "Zee best", 5 );
		std::cout << j;
		j.upGrade();
		std::cout << j;
		RobotomyRequestForm    f = RobotomyRequestForm( "" );
		PresidentialPardonForm p( "" );
		ShrubberyCreationForm  s( "" );
		f.beSigned( j );
		p.beSigned( j );
		s.beSigned( j );
		j.executeForm( f );
		j.executeForm( p );
		j.executeForm( s );
	} catch ( const std::exception &e ) {
		std::cout << e.what() << std::endl;
	}
	return 0;
}