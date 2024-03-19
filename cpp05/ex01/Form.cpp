#include "Form.hpp"

Form::Form(): name(""), sign(false), signGrade(1)
{
	std::cout << "Form: Default constructor called" << std::endl;
};

Form::Form( const std::string nname, const int sgrade ) :
name(nname), sign(false), signGrade(sgrade)
{
	std::cout << "Form: Parameterized constructor called" << std::endl;
	if (signGrade < 1)
		throw Form::GradeTooHighException();
	else if (signGrade > 150)
		throw Form::GradeTooLowException();
};

Form::Form(const Form& other) : name(other.name), signGrade(other.signGrade)
{
	std::cout << "Form: Copy constructor called" << std::endl;
	*this = other;
};

Form& Form::operator=(const Form&)
{
	std::cout << "Form: Copy assignment operator called" << std::endl;
	return *this;
};

Form::~Form()
{
	std::cout << "Form: Destructor called" << std::endl;
};

const std::string Form::getName() const
{
	return name;
};

int Form::getSignGrade() const
{
	return signGrade;
};

bool Form::getSign() const
{
	return sign;
};

std::ostream &operator<<(std::ostream &os, const Form &obj)
{
	os << obj.getName() << ", Form Info: " << obj.getSignGrade() << "." << std::endl;
	return (os);
}

const char *Form::GradeTooHighException::what() const throw()
{
	return ("Grade is too high!");
}

const char *Form::GradeTooLowException::what() const throw()
{
	return ("Grade is too low!");
}
const char *Form::FormAlreadySignedException::what() const throw()
{
    return ("Form is already signed");
}

void Form::beSigned(const Bureaucrat &signer)
{
	if (sign == true)
		throw Form::FormAlreadySignedException();
	if (signer.getGrade() > signGrade)
		throw Form::GradeTooLowException();
	sign = true;
}