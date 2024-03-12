#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include <iostream>
#include <string>
#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
	public:
		RobotomyRequestForm( const std::string target );
		RobotomyRequestForm( const RobotomyRequestForm& other );
		RobotomyRequestForm& operator=( const RobotomyRequestForm& other );
		~RobotomyRequestForm();
	private:
		RobotomyRequestForm();
		const std::string target;
};

#endif