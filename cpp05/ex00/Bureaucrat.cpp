#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
{
	std::cout << "Bureaucrat: Default constructor called" << std::endl;
};

Bureaucrat::Bureaucrat( std::string nname, int ngrade ) : name(nname)
{
	std::cout << "Bureaucrat: Parameterized constructor called" << std::endl;
	if (ngrade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (ngrade > 150)
		throw Bureaucrat::GradeTooLowException();
	else
		grade = ngrade;
};

Bureaucrat::Bureaucrat(const Bureaucrat& other)
{
	std::cout << "Bureaucrat: Copy constructor called" << std::endl;
	*this = other;
};

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
	std::cout << "Bureaucrat: Copy assignment operator called" << std::endl;
	if (this != &other) {
		this->grade = other.grade;
	}
	return *this;
};

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat: Destructor called" << std::endl;
};

const std::string Bureaucrat::getName() const
{
	return name;
};

int Bureaucrat::getGrade() const
{
	return grade;
};

void Bureaucrat::upGrade()
{
	if (grade - 1 < 1)
		throw Bureaucrat::GradeTooHighException();
	grade--;
};

void Bureaucrat::downGrade()
{
	if (grade + 1 > 150)
		throw Bureaucrat::GradeTooLowException();
	grade++;
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &obj)
{
	os << obj.getName() << ", bureaucrat grade" << obj.getGrade() << "." << std::endl;
	return (os);
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
    return ("Grade is too high!");
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
    return ("Grade is too low!");
}