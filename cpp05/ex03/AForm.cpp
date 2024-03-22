#include "AForm.hpp"

AForm::AForm(): name(""), sign(false), signGrade(1), execGrade(1)
{
	std::cout << "AForm: Default constructor called" << std::endl;
};

AForm::AForm( const std::string nname, const int sgrade, const int egrade ) :
name(nname), sign(false), signGrade(sgrade), execGrade(egrade)
{
	std::cout << "AForm: Parameterized constructor called" << std::endl;
	if (signGrade < 1 || execGrade < 1)
		throw AForm::GradeTooHighException();
	else if (signGrade > 150 || execGrade > 150)
		throw AForm::GradeTooLowException();
};

AForm::AForm(const AForm& other) : name(other.name), signGrade(other.signGrade), execGrade(other.execGrade)
{
	std::cout << "AForm: Copy constructor called" << std::endl;
	*this = other;
};

AForm& AForm::operator=(const AForm&)
{
	std::cout << "AForm: Copy assignment operator called" << std::endl;
	return *this;
};

AForm::~AForm()
{
	std::cout << "AForm: Destructor called" << std::endl;
};

const std::string AForm::getName() const
{
	return name;
};

int AForm::getSignGrade() const
{
	return signGrade;
};

int AForm::getExecGrade() const
{
	return execGrade;
};

bool AForm::getSign() const
{
	return sign;
};

std::ostream &operator<<(std::ostream &os, const AForm &obj)
{
	os << obj.getName() << ", AForm Info: " << obj.getSignGrade() << ", " << obj.getExecGrade() << "." << std::endl;
	return (os);
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return ("Grade is too high!");
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return ("Grade is too low!");
}

const char *AForm::FormAlreadySignedException::what() const throw()
{
    return ("Form is already signed");
}

const char *AForm::FormNotSignedException::what() const throw()
{
    return ("Form is not signed");
}

void AForm::beSigned(const Bureaucrat &signer)
{
	if (sign == true)
		throw AForm::FormAlreadySignedException();
	if (signer.getGrade() > signGrade)
		throw AForm::GradeTooLowException();
	sign = true;
}

void AForm::execute(Bureaucrat const & executor) const
{
	(void) executor;
}

void AForm::canExecute(const Bureaucrat& signer) const
{
    if (sign != true)
        throw AForm::FormNotSignedException();
    if (signer.getGrade() > execGrade)
        throw AForm::GradeTooLowException();
}