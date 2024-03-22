#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5)
{
	std::cout << "PresidentialPardonForm: Default constructor called" << std::endl;
};

PresidentialPardonForm::PresidentialPardonForm( const std::string ttarget ) :
AForm("PresidentialPardonForm", 25, 5), target(ttarget)
{
	std::cout << "PresidentialPardonForm: Parameterized constructor called" << std::endl;
};

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) : AForm(other), target(other.target)
{
	std::cout << "PresidentialPardonForm: Copy constructor called" << std::endl;
	*this = other;
};

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
	std::cout << "PresidentialPardonForm: Copy assignment operator called" << std::endl;
	if (this != &other) {
		//No other vars to heir
	}
	return *this;
};

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "PresidentialPardonForm: Destructor called" << std::endl;
};

std::string const &PresidentialPardonForm::getTarget(void) const
{
	return (this->target);
}

void PresidentialPardonForm::execute( Bureaucrat const &executor ) const
{
	this->canExecute(executor);
	std::cout << target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}