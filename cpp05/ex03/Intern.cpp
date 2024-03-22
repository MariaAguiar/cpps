#include "Intern.hpp"

Intern::Intern()
{
	std::cout << "Intern: Default constructor called" << std::endl;
};

Intern::Intern(const Intern& other)
{
	std::cout << "Intern: Copy constructor called" << std::endl;
	*this = other;
};

Intern& Intern::operator=(const Intern&)
{
	std::cout << "Intern: Copy assignment operator called" << std::endl;
	return *this;
};

Intern::~Intern()
{
	std::cout << "Intern: Destructor called" << std::endl;
};

AForm *newShrubberyCreationForm(const std::string& target)
{
    return (new ShrubberyCreationForm(target));
}

AForm *newRobotomyRequestForm(const std::string& target)
{
    return (new RobotomyRequestForm(target));
}

AForm *newPresidentialPardonForm(const std::string& target)
{
    return (new PresidentialPardonForm(target));
}

const char *Intern::FormDoesNotExist::what() const throw()
{
    return ("Form does not exist");
}

AForm *(*Intern::formConstructors[3])(const std::string &target)
                                        = { &newShrubberyCreationForm,
                                            &newRobotomyRequestForm, 
                                            &newPresidentialPardonForm };

AForm *Intern::makeForm( const std::string form, const std::string target )
{
	std::string	forms[3] = {"ShrubberyCreation", "RobotomyRequest", "PresidentialPardon"};
	int			i = 0;
	while (i < 3 && forms[i].compare(form))
		i++;
	if (i == 3)
		throw Intern::FormDoesNotExist();
	else
	{
		std::cout << "Intern creates " << form << std::endl;
		return formConstructors[i](target);
	}
	return 0;
};
