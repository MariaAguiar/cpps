#include "ClapTrap.hpp"

ClapTrap::ClapTrap( std::string name )
{
	std::cout << "ClapTrap: Parameterized constructor called" << std::endl;
	Name = name;
	HitPoints = 10;
	EnergyPoints = 10;
	AttackDamage = 0;
};

ClapTrap::ClapTrap()
{
	std::cout << "ClapTrap: Default constructor called" << std::endl;
};

ClapTrap::ClapTrap(const ClapTrap& other)
{
	std::cout << "ClapTrap: Copy constructor called" << std::endl;
	*this = other;
};

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
	std::cout << "ClapTrap: Copy assignment operator called" << std::endl;
	if (this != &other) {
		this->Name = other.Name;
		this->HitPoints = other.HitPoints;
		this->EnergyPoints = other.EnergyPoints;
		this->AttackDamage = other.AttackDamage;
	}
	return *this;
};

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap: Destructor called" << std::endl;
};


void ClapTrap::attack(const std::string& target)
{
	if (EnergyPoints > 0)
	{
		std::cout << Name << " attacks! " << target << " lost " << AttackDamage << " hitPoints!" << std::endl;
		EnergyPoints--;
		std::cout << Name << "'s attacking action cost them 1 EnergyPoint." << std::endl;
	}
	else
		std::cout << "Can't attack! " << Name << " ran out of EnergyPoints!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (HitPoints > 0)
	{
		HitPoints -= amount;
		std::cout << Name << " took " << amount << " hitPoints of damage!" << std::endl;
	}
	else
		std::cout << "Mercy! " << Name << " can't lose more HitPoints!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (EnergyPoints > 0)
	{
		EnergyPoints--;
		std::cout << Name << "'s healing action cost them 1 EnergyPoint." << std::endl;
		HitPoints += amount;
		std::cout << Name << " regained " << amount << " HitPoints!" << std::endl;
	}
	else
		std::cout << "Can't heal! " << Name << " ran out of EnergyPoints!" << std::endl;
}
