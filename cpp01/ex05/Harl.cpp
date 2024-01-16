
#include "Harl.hpp"

Harl::Harl(){}

void Harl::debug()
{
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void Harl::info()
{
    std::cout << "I cannot believe adding extra bacon costs more money. You did't put enough bacon in my burger! If you did, I wouldn't be asking for more!" << std::endl;
}

void Harl::warning()
{
     std::cout << "I think I deserve to have some extra bacon for free. I've been coming for years whereas you started working here since last month." << std::endl;
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
    t_func		functions[] = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error, &Harl::invalidComplaint};
	std::string	levels[5] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int			i = 0;

	while (i < 4 && levels[i].compare(level))
		i++;
	(this->*functions[i])();
}

Harl::~Harl(){}