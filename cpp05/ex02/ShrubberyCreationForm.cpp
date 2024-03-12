#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137)
{
	std::cout << "ShrubberyCreationForm: Default constructor called" << std::endl;
};

ShrubberyCreationForm::ShrubberyCreationForm( const std::string ttarget ) : target(ttarget),
AForm("ShrubberyCreationForm", 145, 137)
{
	std::cout << "ShrubberyCreationForm: Parameterized constructor called" << std::endl;
};

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : AForm(other), target(other.target)
{
	std::cout << "ShrubberyCreationForm: Copy constructor called" << std::endl;
	*this = other;
};

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
	std::cout << "ShrubberyCreationForm: Copy assignment operator called" << std::endl;
	if (this != &other) {
		//No other vars to heir
	}
	return *this;
};

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm: Destructor called" << std::endl;
};
