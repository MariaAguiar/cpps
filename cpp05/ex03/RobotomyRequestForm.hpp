#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include <iostream>
#include <string>
#include <cstdlib>
#include "AForm.hpp"
#include <ctime>

class RobotomyRequestForm : public AForm
{
	public:
		RobotomyRequestForm( const std::string target );
		RobotomyRequestForm( const RobotomyRequestForm& other );
		RobotomyRequestForm& operator=( const RobotomyRequestForm& other );
		~RobotomyRequestForm();
		void execute( Bureaucrat const &executor ) const;
		std::string const &getTarget(void) const;
	private:
		RobotomyRequestForm();
		const std::string target;
};

#endif