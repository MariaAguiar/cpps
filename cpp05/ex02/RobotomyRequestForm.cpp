#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45)
{
	std::cout << "RobotomyRequestForm: Default constructor called" << std::endl;
};

RobotomyRequestForm::RobotomyRequestForm( const std::string ttarget ) :
AForm("RobotomyRequestForm", 72, 45), target(ttarget)
{
	std::cout << "RobotomyRequestForm: Parameterized constructor called" << std::endl;
};

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) : AForm(other), target(other.target)
{
	std::cout << "RobotomyRequestForm: Copy constructor called" << std::endl;
	*this = other;
};

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
	std::cout << "RobotomyRequestForm: Copy assignment operator called" << std::endl;
	if (this != &other) {
		//No other vars to heir
	}
	return *this;
};

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm: Destructor called" << std::endl;
};

std::string const &RobotomyRequestForm::getTarget(void) const
{
	return (this->target);
}

void RobotomyRequestForm::execute( Bureaucrat const &executor ) const
{
	this->canExecute(executor);
    srand(std::time(0));
    if (rand() % 2 == 0)
        std::cout << target << " has been robotomized successfully" << std::endl;
    else
        std::cout << "The robotomy of " << target << " failed" << std::endl;
}
