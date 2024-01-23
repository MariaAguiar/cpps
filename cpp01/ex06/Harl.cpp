
#include "Harl.hpp"

Harl::Harl(){}

void Harl::debug()
{
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
	info();
}

void Harl::info()
{
    std::cout << "I cannot believe adding extra bacon costs more money. You did't put enough bacon in my burger! If you did, I wouldn't be asking for more!" << std::endl;
	warning();
}

void Harl::warning()
{
     std::cout << "I think I deserve to have some extra bacon for free. I've been coming for years whereas you started working here since last month." << std::endl;
	error();
}

void Harl::error()
{
    std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void	Harl::invalidComplaint(void)
{
	std::cout << "Unreasonable complaint\n";
}

void Harl::complain( std::string level )
{
	std::string	levels[5] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int			i = 0;

	while (i < 4 && levels[i].compare(level))
		i++;
	switch (i)
	{
	case 0:
		debug();
		break;
	case 1:
		info();
		break;
	case 2:
		warning();
		break;
	case 3:
		error();
		break;
	default:
		invalidComplaint();
		break;
	}
}

Harl::~Harl(){}